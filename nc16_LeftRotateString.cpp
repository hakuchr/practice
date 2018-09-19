#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        string lrs;
        for (int i = n; i < len; ++i){
            lrs.push_back(str[i]);
        }
        for (int i = 0; i < n; ++i){
            lrs.push_back(str[i]);
        }
        return lrs;
    }
};

int main()
{
    Solution S;
    string str;
    char c;
    int n;
    cin >> n;
    while (cin >> c){
        str.push_back(c);
    }
    cout << S.LeftRotateString(str, n);
    system("pause");
    return 0;
}