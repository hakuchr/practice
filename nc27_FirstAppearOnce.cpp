#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if (state[ch] == 0){
            data.push(ch);
            state[ch] = 1;
        }else if (state[ch] == 1){
            state[ch] = -1;
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while (!data.empty()){
            if (state[data.front()] == 1)
                return data.front();
            else
                data.pop();
        }
        return '#';    
    }
private:
    int state[256]{0};
    queue<char> data;
};


//test: google