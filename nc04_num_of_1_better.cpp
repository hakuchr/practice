//时间O(log(10,n))
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt = 0, k;
        for (int i = 1; k = n / i; i *= 10){
            cnt += (k / 10) * i;
            int cur = k % 10;
            if (cur > 1)
                cnt += i;
            else if (cur == 1)
                cnt += n - k * i + 1;
        }
        return cnt;
    }
};

int main()
{
    Solution S;
    int n;
    while(cin >> n)
        cout << S.NumberOf1Between1AndN_Solution(n) << endl;
    system("pause");
    return 0;
}

//整数中1出现的次数（从1到n整数中1出现的次数）
//https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking