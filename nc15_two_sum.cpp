#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> pair;
        unordered_map<int, int> map;
        for (int i = 0; i < array.size(); ++i)
            map[array[i]] = i;
        for (int i = 0; i < array.size(); ++i){
            int complement = sum - array[i];
            if (map.find(complement) != map.end()){
                pair.push_back(array[i]);
                pair.push_back(complement);
                break;
            }
        }
        return pair;
    }
};