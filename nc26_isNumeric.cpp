#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string[0] == '\0')
            return false;
        bool start = false;
        bool flag_sign = false;
        bool flag_dot = false;
        bool flag_e = false;
        bool flag_e_sign = false;
        for (; *string != '\0'; ++string){
            if (!start){
                if (*string - '0' > -1 && *string - '0' < 10){
                    start = true;
                }else if (!flag_sign && (*string == '+' || *string == '-')){
                    flag_sign = true;
                }else
                    return false;
            }else{
                if (*string - '0' < 0 || *string - '0' > 9){
                    if (*string == '.'){
                        if (flag_e == true)
                            return false;
                        if (flag_dot == false)
                            flag_dot = true;
                        else
                            return false;
                        if (*(string + 1) == '\0' || *(string + 1) == 'e')
                            return false;
                    }
                    else if (*string == 'e'){
                        if (flag_e == false)
                            flag_e = true;
                        else
                            return false;
                        if (*(string + 1) == '\0' || *(string + 1) == '.')
                            return false;
                    }
                    else if (*string == '+' || *string == '-'){
                        if (*(string - 1) != 'e')
                            return false;
                        if (*(string + 1) == '\0')
                            return false;
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }

};

int main()
{
    Solution S;
    char* string = "+-5";
    cout << S.isNumeric(string) << endl;
    system("pause");
    return 0;
}




//例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
//但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。