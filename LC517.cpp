#include <iostream>
#include <string>
#include <algorithm>
// 未完成
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        if (key.empty())
            return 0;
        int tmp = 1;
        if (ring[0] == key[0]){
            key = key.substr(1);
            tmp = 2;
        }
        return min(findRotateSteps(move_c(ring), key) + tmp, findRotateSteps(move_a(ring), key) + tmp);
    }
    string move_c(string ring){
        string s(" ");
        s[0] = ring[ring.length() - 1];
        s.append(ring.substr(0, ring.length() - 1));
        return s;
    }
    string move_a(string ring){
        string s;
        s = ring.substr(1);
        s.append(ring.substr(0, 1));
        return s;
    }
};

int main()
{
    string ring, key;
    Solution S;
    cin >> ring >> key;
    cout << S.findRotateSteps(ring, key) << endl;
    system("pause");
    return 0;
}