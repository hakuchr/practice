#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> all;
		if (str.empty())
			return all;
		sort(str.begin(), str.end());
		permutation_sub(all, str, 0);
		return all;
	}
private:
	void permutation_sub(vector<string> &all, string str, string::size_type n){    //递归函数
		if (n == str.size()){    //递归出口；当指定序号超出串末尾时，保存该串
			all.push_back(str);
			return;
		}
		for (string::size_type i = n; i != str.size(); i++){
			if (i != n && str[i] == str[n])
				continue;
			swap(str[i], str[n]);
			permutation_sub(all, str, n + 1);    //对以下一个字符开头的串进行全排列
		}
	}
};

int main(){
	string s;
	getline(cin, s);
	if (s.size() > 9)
		return -1;
	Solution solve;
	vector<string> all;
	all = solve.Permutation(s);
	for (vector<string>::iterator iter = all.begin(); iter != all.end(); iter++){
		cout << *iter << endl;
	}
	return 0;
}

/*
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/