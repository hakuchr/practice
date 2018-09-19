#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <cstring>  
#include <string>  
#include <queue>  
#include <stack>  
#include <map>  
#include <set>  
#include <cmath>  
#include <vector> 
#define max_ 10
#define inf 0x3f3f3f3f
#define ll long long
#define les 1e-8
using namespace std;
set<string> ss;			//用set记录队列中已经存在过的串
map<string, int> mp; 	//用map记录走过的步数
queue<string> q;
int bfs(string sg);

int main(int argc, char const *argv[]){
	string s, sg;
	int step;
	cin >> s >> sg;
	mp[s] = 0;
	q.push(s);
	ss.insert(s);
	step = bfs(sg);
	printf("%d\n", step);
	return 0;
}

int bfs(string sg)
{
	while (!q.empty()){
		string s = q.front();
		q.pop();
		int k;
		int l = s.size();
		for (int i = 0; i < l; i++){
			if (s[i] == '*'){	//找空杯子的位置
				k = i;
				break;
			}
		}
		for (int i = max(0, k - 3); i <= min(l - 1, k + 3); i++){
			string tmp = s;
			swap(tmp[i], tmp[k]);
			if (ss.find(tmp) == ss.end())
			{
				q.push(tmp);
				ss.insert(tmp);
				if (mp[tmp] == 0)
					mp[tmp] = mp[s] + 1;
				else
					mp[tmp] = min(mp[tmp], mp[s] + 1);  //对应字符串tmp的最小步数
				if (tmp == sg)
					return mp[tmp];	//当得到目标串后返回步数 --hakuchr
			}
		}
	}
	return -1;
}

//题目：青蛙跳杯子 bfs https://blog.csdn.net/Lngxling/article/details/79543813