#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() < 5) return false;
        sort(numbers.begin(), numbers.end());
        if (numbers[0] != 0){
            for (int i = 0; i < numbers.size() - 1; ++i){
                if (numbers[i + 1] - numbers[i] != 1)
                    return false;
            }
            return true;
        }else if (numbers[0] == 0 && numbers[1] != 0){
            int flag = 1;
            for (int i = 1; i < numbers.size() - 1; ++i){
                int diff = numbers[i + 1] - numbers[i];
                if (diff > 2 || diff == 0)
                    return false;
                if (diff == 2){
                    if (flag == 1) flag = 0;
                    else return false;
                }
            }
            return true;
        }else if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] != 0){
            int flag = 2;
            for (int i = 2; i < numbers.size() - 1; ++i){
                int diff = numbers[i + 1] - numbers[i];
                if (diff > 3 || diff == 0)
                    return false;
                if (diff == 3){
                    if (flag == 2) flag = 0;
                    else return false;
                }
                if (diff == 2){
                    if (flag > 0) --flag;
                    else return false;
                }
            }
            return true;
        }else if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0){
            int diff = numbers[4] - numbers[3];
            if (diff > 4 || diff == 0)
                return false;
            return true;
        }else if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0 && numbers[3] == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution S;
    int n;
    vector<int> numbers;
    while (cin >> n){
        numbers.push_back(n);
    }
    cout << S.IsContinuous(numbers) << endl;
    system("pause");
    return 0;
}