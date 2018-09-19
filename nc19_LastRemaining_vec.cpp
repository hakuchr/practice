//时间复杂度O(mn)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0 || m <= 0)
            return -1;
        vector<int> arr(n, 0);
        int i = -1, step = 0, cnt = n;
        while (cnt > 0){
            ++i;
            if (i >= n) i = 0;
            if (arr[i] == -1)
                continue;
            ++step;
            if (step == m){
                arr[i] = -1;
                step = 0;
                --cnt;
            }
        }
        return i;
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