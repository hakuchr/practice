#include<bits/stdc++.h>  
using namespace std;  
const int maxn = 100000;  
typedef long long ll;  
string s[500000];  
int step[500000];  
int bfs()  
{  
    set<string> visited;  
    int l,r;  
    l = 0;  
    r = 1;  
    string t,tt;  
    cin>>t>>tt;  
    s[0] = t;  
    step[0] = 0;  
    visited.insert(s[0]);  
    while(l < r)  
    {  
        string c = s[l];  
        int location;  //找*的位置   
        for(int i = 0;i < c.size();i ++)  
        if(c[i] == '*')  
        {  
            location  = i;  
            break;  
        }  
        //下面开始列举可能跳的情况  
        if(location - 1 >= 0)  
        {  
            string n = c;  
            int tmp = location - 1;  
            char cc = n[location];  
            n[location] = n[tmp];  
            n[tmp] = cc;  
            if(visited.find(n) == visited.end())  
            {  
                s[r] = n;  //r为跳跃得到的字符串的序号
                step[r] = step[l] + 1;  
                if(n == tt) return step[r];  //每个放入set的字符串对应一个跳跃次数step
                visited.insert(n);  
                r ++;  
            }  
        }   
        if(location - 2 >= 0)  
        {  
            string n = c;  
            int tmp = location - 2;  
            char cc = n[location];  
            n[location] = n[tmp];  
            n[tmp] = cc;  
            if(visited.find(n) == visited.end())  
            {  
                s[r] = n;  
                step[r] = step[l] + 1;  
                if(n == tt) return step[r];  
                visited.insert(n);  
                r ++;  
            }  
        }   
        if(location - 3 >= 0)  
        {  
            string n = c;  
            int tmp = location - 3;  
            char cc = n[location];  
            n[location] = n[tmp];  
            n[tmp] = cc;  
            if(visited.find(n) == visited.end())  
            {  
                s[r] = n;  
                step[r] = step[l] + 1;  
                if(n == tt) return step[r];  
                visited.insert(n);  
                r ++;  
            }  
        }   
        if(location + 1 <= c.size() -1)  
        {  
            string n = c;  
            int tmp = location + 1;  
            char cc = n[location];  
            n[location] = n[tmp];  
            n[tmp] = cc;  
            if(visited.find(n) == visited.end())  
            {  
                s[r] = n;  
                step[r] = step[l] + 1;  
                if(n == tt) return step[r];  
                visited.insert(n);  
                r ++;  
            }  
        }  
        if(location + 2 <= c.size() -1)  
        {  
            string n = c;  
            int tmp = location + 2;  
            char cc = n[location];  
            n[location] = n[tmp];  
            n[tmp] = cc;  
            if(visited.find(n) == visited.end())  
            {  
                s[r] = n;  
                step[r] = step[l] + 1;  
                if(n == tt) return step[r];  
                visited.insert(n);  
                r ++;  
            }  
        }  
        if(location + 3 <= c.size() -1)  
        {  
            string n = c;  
            int tmp = location + 3;  
            char cc = n[location];  
            n[location] = n[tmp];  
            n[tmp] = cc;  
            if(visited.find(n) == visited.end())  
            {  
                s[r] = n;  
                step[r] = step[l] + 1;  
                if(n == tt) return step[r];  
                visited.insert(n);  
                r ++;  
            }  
        }  
        l ++;  
    }  
    return -1;  
}  
int main()  
{  
    cout<<bfs()<<endl;  
    return 0;   
}  