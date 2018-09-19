#include<vector>
#include<iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = INT_MIN;
        int sum_tmp = 0;
        for (int i = 0; i < array.size(); ++i){
            if (sum_tmp <= 0)
                sum_tmp = array[i];
            else
                sum_tmp += array[i];
            if (sum < sum_tmp)
                sum = sum_tmp;
        }
        return sum;
    }
};

int main()
{
    Solution S;
    vector<int> array;
    int num;
    while (cin >> num){
        array.push_back(num);
    }
    cout << S.FindGreatestSumOfSubArray(array) << endl;
    system("pause");
    return 0;
}