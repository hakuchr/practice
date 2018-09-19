//利用map，时间复杂度降为O(nlogn)
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target){
		vector<int> ret(2, 0);
		unordered_map<int, int> map; //也可以用hash_map，时间O(n)
		for (int i = 0; i < nums.size(); ++i){
			map[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); ++i){
			int complement = target - nums[i];
			unordered_map<int, int>::iterator iter = map.find(complement);
			if (iter != map.end() && iter->second != i){
				ret[0] = i;
				ret[1] = iter->second;
				return ret;
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