#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.empty())
            return 0;
        int start = 0, middle = 0, p = -1, cnt = 0;
        int end = data.size() - 1;
        while (start <= end){ //二分查找，找到一个值等于k的位置
            middle = (end + start) / 2;
            if (data[middle] == k){
                p = middle;
                break;
            }
            else if (data[middle] > k)
                end = middle - 1;
            else if (data[middle] < k)
                start = middle + 1;
        }
        if (p == -1) //未找到
            return 0;
        while (data[p] == k){
            ++cnt;
            --p; //往左边寻找等于k的数
        }
        p = middle + 1;
        while (data[p] == k){
            ++cnt;
            ++p; //往右边寻找等于k的数
        }
        return cnt;
    }
};

int main()
{
    Solution S;
    int n, k;
    vector<int> numbers;
    cin >> k;
    while (cin >> n)
        numbers.push_back(n);
    cout << S.GetNumberOfK(numbers, k) << endl;
    system("pause");
    return 0;
}

//输入：目标数字k, 递增数组
//Input example: 5 1 1 1 2 2 4 5 5 6 8 9 
//(find num of 5)