#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int num = 0, t, flag = 0;
        if (str[0] != '-' && str[0] != '+' && (str[0] - '0' < 0 || str[0] - '0' > 9))
            return 0;
        if (str[0] == '-')
            flag = -1;
        if (str[0] == '+')
            flag = 1;
        for (int i = flag * flag; i < str.length(); ++i){
            if (str[i] - '0' < 0 || str[i] - '0' > 9)
                return 0;
            t = str[i] - '0';
            num = num * 10 + t;
        }
        if (flag != 0)
            return num * flag;
        else
            return num;
    }
};
int main()
{
    Solution S;
    string str;
    while (cin >> str)
        cout << S.StrToInt(str) << endl;
    system("pause");
    return 0;
}

//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking