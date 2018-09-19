//递归。使用递推公式
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0)
            return -1;
        if (n == 1)
            return 0;
        else
            return (LastRemaining_Solution(n - 1, m) + m) % n;
    }
};


int main()
{
    Solution S;
    int n, m;
    cin >> n >> m;
    cout << S.LastRemaining_Solution(n, m) << endl;
    system("pause");
    return 0;
}

//https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking