#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int index = 0, len = data.size();
        sort(data.begin(), data.end());
        if (data[0] != data[1]){
            *num1 = data[0];
            index = 1;
        }
        for (int i = 1; i < len - 2; ++i){
            if (data[i] != data[i - 1] && data[i] != data[i + 1]){
                if (index == 0){
                    *num1 = data[i];
                    index = 1;
                }
                else if (index == 1){
                    *num2 = data[i];
                    index = 2;
                    break;
                }
            }
        }
        if (data[len - 1] != data[len - 2])
            *num2 = data[len - 1];
    }
};

int main()
{
    Solution S;
    int n , n1 = 0, n2 = 0;
    int *num1 = &n1, *num2 = &n2;
    vector<int> numbers;
    while (cin >> n)
        numbers.push_back(n);
    S.FindNumsAppearOnce(numbers, num1, num2);
    cout << *num1 << ", " << *num2 << endl;
    system("pause");
    return 0;
}

//test: 2 5 5 1 4 2 9 4 3 3 6 3 3 6 7 9 8 8
// 4 6 2 2 3 3 8 8 9 9 1000000 1000000