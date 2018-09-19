#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (strlen(pattern) == 0) return strlen(str) == 0;
        if (strlen(str) == 0){
            if (strlen(pattern) > 1 && pattern[1] == '*')
                return match(str, pattern + 2);
            else
                return false;
        }
        bool first_match = (str[0] == pattern[0] || pattern[0] == '.');
        if (strlen(pattern) > 1 && pattern[1] == '*'){
            return match(str, pattern + 2) || first_match && match(str + 1, pattern);
        }
        else
            return first_match && match(str + 1, pattern + 1);
    }
};