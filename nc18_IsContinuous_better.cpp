#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() < 5) return false;
        int max = -1, min = 14, tmp = 0;
        for (int i = 0; i < numbers.size(); ++i){
            if (numbers[i] < 0 || numbers[i] > 13) return false;
            if (numbers[i] == 0) continue;
            if (numbers[i] == tmp) return false;
            tmp = numbers[i];
            if (max < numbers[i]) max = numbers[i];
            if (min > numbers[i]) min = numbers[i];
            if (max - min > 4) return false;
        }
        return true;
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

//https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking