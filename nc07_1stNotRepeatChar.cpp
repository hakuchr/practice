#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty())
            return -1;
        unordered_map<char, int> char_count; //字符和对应的计数
        unordered_map<char, int> char_location; //字符和对应的初次出现位置
        for (int i = 0; i < str.size(); ++i){
            ++char_count[str[i]]; 
            if (char_count[str[i]] == 1)
                char_location.insert(pair<char, int> (str[i], i)); //字符初次出现时保存位置
        }
        int first_location = str.size();
        for (unordered_map<char, int>::iterator iter = char_count.begin(); iter != char_count.end(); ++iter){
            if (iter->second == 1){
                if(first_location > char_location[iter->first])
                    first_location = char_location[iter->first];
            }
        }
        if (first_location == str.size())
            return -1;
        else
            return first_location;
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

//https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking