#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lim = 1000000007;
	int InversePairs(vector<int> data) {
		int len = data.size();
		if (len <= 0)
			return 0;
		vector<int> copy;
		for (int i = 0; i < len; ++i)
			copy.push_back(data[i]);
		int cnt = InversePairsCore(data, copy, 0, len - 1);
		return cnt;
	}
	int InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end){
		if (start == end){
			copy[start] = data[end];
			return 0;
		}
		int len = (end - start) / 2;
		int left = InversePairsCore(copy, data, start, start + len) % lim;
		int right = InversePairsCore(copy, data, start + len + 1, end) % lim;

		int i = start + len;
		int j = end;
		int indexcopy = end;
		int cnt = 0;
		while (i >= start && j >= start + len + 1){
			if (data[i] > data[j]){
				copy[indexcopy--] = data[i--];
				cnt += j - (start + len);
                if (cnt >= lim)
                    cnt %= lim;
			}
			else{
				copy[indexcopy--] = data[j--];
			}
		}
		while (i >= start)
			copy[indexcopy--] = data[i--];
		while (j >= start + len + 1)
			copy[indexcopy--] = data[j--];
		return (left + right + cnt) % lim;
	}
};

int main()
{
	Solution S;
	int n;
	vector<int> numbers;
	while (cin >> n)
		numbers.push_back(n);
	cout << S.InversePairs(numbers) << endl;
	system("pause");
	return 0;
}

//test input: 7 6 5 4 9 8 3 2
//采用归并排序的思路
//https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking