//时间O(n)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        vector<int> counts(n + 1, 0); //向量用于记录每个数中1的个数
        int sum = 0;
        for (int i = 0; i < counts.size(); ++i){
            counts[i] = counts[i/10] + (i % 10 == 1);
            //数i中包含1的个数等于数i右移一位（除以10）后得到的数中包含1的个数，加上i的个位中1的个数
            sum += counts[i];
        }
        return sum;
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