#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty())
            return -1;
        unordered_map<char, int> char_count;
        for (int i = 0; i < str.size(); ++i){
            ++char_count[str[i]]; //对字符出现次数计数
        }
        //由于unordered_map与原字符串str的顺序不同，寻找第一个非重复字符时，
        //对str遍历，找到第一个计数为1的字符，返回位置i
        for (int i = 0; i <str.size(); ++i){
            if (char_count[str[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution S;
    string str;
    while(cin >> str)
        cout << S.FirstNotRepeatingChar(str) << endl;
    system("pause");
    return 0;
}