#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int num = 0;
        bool start = false;
        int sign = 1;
        string::iterator iter;
        for (iter = str.begin(); iter != str.end(); ++iter)
        {
            if (!start && (*iter == '+' || *iter == '-'))
            {
                start = true;
                if (*iter == '-')
                    sign = -1;
                continue;
            }
            if (!start && *iter == ' ')
                continue;
            if (*iter < '0' || *iter > '9')
                break;
            else{
                start = true;
                if (sign == 1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && *iter > '7')))
                    return INT_MAX;
                if (sign == -1 && (num*sign < INT_MIN / 10 || (num*sign == INT_MIN / 10 && *iter > '8')))
                    return INT_MIN;
                num = num * 10 + (*iter - '0');
            }
        }
        return num*sign;
    }
};

int main()
{
    string str;
    Solution S;
    while (getline(cin, str)){
        cout << S.myAtoi(str) << endl;
    }
    return 0;

}

//https://leetcode.com/problems/string-to-integer-atoi/description/