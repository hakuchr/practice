#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int x_r = 0;
        do
        {
            if (x_r * 10 / 10 != x_r)
                return 0;
            x_r = x_r * 10 + x % 10;
            x = x / 10;
        } while (x != 0);
        return x_r;
    }
};

int main()
{
    int x;
    Solution S;
    while(cin >> x)
    {

        cout << S.reverse(x) << endl;
    }
    return 0;

}

//https://leetcode.com/problems/reverse-integer/description/