#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int findRadius(vector<int>& houses, vector<int>& heaters){
        int r = 0;
        int i = 0;
        int j = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        if (houses[0] < heaters[0])
            r = heaters[0] - houses[0];
        while(i < heaters.size() - 1 && j < houses.size()){
            if (houses[j] > heaters[i]){
                if (houses[j] <= heaters[i + 1]){
                    int tmp_l = houses[j] - heaters[i];
                    int tmp_r = heaters[i + 1] - houses[j];
                    int tmp = (tmp_l < tmp_r) ? tmp_l : tmp_r; 
                    if (r < tmp)
                        r = tmp;
                }else{
                    ++i;
                    --j;
                }
            }
            ++j;
        }
        if (i = heaters.size()){
            if (r < houses[houses.size() - 1] - heaters[i - 1] )
                r = houses[houses.size() - 1] - heaters[i - 1];
        }
        return r;
    }
};