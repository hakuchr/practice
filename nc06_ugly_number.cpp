#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;
        if (index == 1)
            return 1;
        int t2 = 0, t3 = 0, t5 = 0, u_num = 1;
        vector<int> arr;
        arr.push_back(u_num);
        for (int i = 1; i < index; ++i){
            u_num = min(arr[t2]*2, min(arr[t3]*3, arr[t5]*5));
            if (u_num == arr[t2]*2) ++t2;
            if (u_num == arr[t3]*3) ++t3;
            if (u_num == arr[t5]*5) ++t5;
            arr.push_back(u_num);
        }
        return u_num;
    }
};

int main()
{
    Solution S;
    int index;
    //for (index = 1; index < 51; ++index)
    //    cout << index << ": " << S.GetUglyNumber_Solution(index) << endl;
    while (cin >> index)
        cout << S.GetUglyNumber_Solution(index) << endl;
    system("pause");
    return 0;
}

//https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2