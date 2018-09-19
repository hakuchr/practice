#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        if (len < 2)
            return A;
        vector<int> B(len, 1);
        for (int i = 1; i < len; ++i){
            B[i] = B[i - 1] * A[i - 1];
        }
        int r = 1;
        for (int i = len - 2; i > -1; --i){
            r *= A[i + 1];
            B[i] *= r;
        }
        return B;
    }
};

int main()
{
    Solution S;
    int n;
    vector<int> numbers, B;
    while (cin >> n)
        numbers.push_back(n);
    B = S.multiply(numbers);
    for (int i = 0; i < B.size(); ++i)
        cout << B[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}
//test: 3 4 5 6 7
//https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking