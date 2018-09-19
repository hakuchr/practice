#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        string rstr = "", tmp = "";
        for (int i = 0; i < str.length(); ++i){
            if (str[i] == ' '){
                rstr = " " + tmp + rstr;
                tmp = "";
            }else
                tmp += str[i];
        }
        rstr = tmp + rstr;
        return rstr;
    }
};

int main()
{
    Solution S;
    string str;
    getline(cin, str);
    cout << S.ReverseSentence(str) << endl;
    system("pause");
    return 0;
}

//https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking