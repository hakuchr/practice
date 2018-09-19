#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        for (int i = ceil(sqrt(2 * sum)); i > 1; --i){
            vector<int> seq;
            int a = 0;
            if (i % 2 == 0 && sum % i != 0 && sum % (i / 2) == 0){
                a = sum / i - i / 2 + 1;
            }else if (i % 2 != 0 && sum % i == 0){
                a = sum / i - i / 2;
            }
            if (a > 0){
                for (int t = a; t < a + i; ++t)
                    seq.push_back(t);
                res.push_back(seq);
            }
        }
        return res;
    }
};