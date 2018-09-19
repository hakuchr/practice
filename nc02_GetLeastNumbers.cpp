#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>

using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {	//利用堆排序，O(N*logK)
		vector<int> array;
		if (input.size() == 0 || k <= 0 || input.size() < k)
			return array;
		multiset<int, greater<int>> least_set;	//multiset作为堆实现；由大到小排序
		multiset<int, greater<int>>::iterator greater_iter;
		vector<int>::iterator iter;
		for (iter = input.begin(); iter != input.end(); ++iter){
			if (least_set.size() < k)
				least_set.insert(*iter);	//按原顺序将前k个数插入set
			else{
				greater_iter = least_set.begin();
				if (*iter < *greater_iter){	//当input中所指的数小于set最大数时，删除该最大数，并插入所指的数
					least_set.erase(greater_iter);
					least_set.insert(*iter);
				}
			}
		}
		multiset<int, greater<int>>::reverse_iterator r_iter; //用反向容器遍历set，按从小到大的顺序输出
		for (r_iter = least_set.rbegin(); r_iter != least_set.rend(); ++r_iter)
			array.push_back(*r_iter);

		return array;
	}
};

int main(){
	vector<int> array;
	vector<int> input;
	int n, k;

	cin >> k;
	while (cin >> n && n != -1){
		input.push_back(n);
	}

	Solution s;
	array = s.GetLeastNumbers_Solution(input, k);
	for (vector<int>::iterator iter = array.begin(); iter != array.end(); ++iter)
		cout << *iter << ", ";
	return 0;
	/*
	最小的K个数
	输入n个整数，找出其中最小的K个数。例如输入4, 5, 1, 6, 2, 7, 3, 8这8个数字，则最小的4个数字是1, 2, 3, 4, 。
	https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=2
	*/
}
