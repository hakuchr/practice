#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> counts(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            counts[i] = counts[i & (i - 1)] + 1;
        return counts;
    }
};

int main()
{
    int num;
    vector<int> count;
    Solution S;
    while(cin >> num){
        count = S.countBits(num);
        for (vector<int>::iterator iter = count.begin(); iter != count.end(); ++iter){
            cout << *iter << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}