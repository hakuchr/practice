//迭代。利用递推公式
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0)
            return -1;
        int s = 0;
        for (int i = 2; i <= n; ++i)
            s = (s + m) % i;
        return s;
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
//56789 20145
//24801