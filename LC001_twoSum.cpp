#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> ret(2,0);
        for (int i = 0; i < nums.size() - 1; ++i){
            for (int j = i + 1; j < nums.size(); ++j){
                if (nums[i] + nums[j] == target){
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> num;
    vector<int> output;
    int n;
    int target = 9;
    Solution S;
    cout << "Input nums: " << endl;
    while (cin >> n){
        num.push_back(n);
    }
    //cout << "Input target: " << endl;
    //cin >> target;
    output = S.twoSum(num, target);
    for (int i = 0; i < output.size(); ++i)
        cout << output[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}