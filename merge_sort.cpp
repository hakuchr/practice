//归并排序
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> merge_sort(vector<int> arr) {
		int len = arr.size();
		if (len < 2)
			return arr;
		int middle = len / 2;
		vector<int> left = vector_sub(arr, 0, middle);
		vector<int> right = vector_sub(arr, middle, len);
		return merge(merge_sort(left), merge_sort(right));
	}
	//函数返回vector从序号beg到end但不包括end的子集
	vector<int> vector_sub(vector<int> &vec, int beg, int end){
		vector<int> res(end - beg, 0);
		for (int i = beg; i < end; ++i)
			res[i - beg] = vec[i];
		return res;
	}
	vector<int> merge(vector<int> left, vector<int> right){
		vector<int> res;
		int i = 0, j = 0;
		while (i < left.size() && j < right.size()){
			if (left[i] <= right[j]){
				res.push_back(left[i]);
				++i;
			}
			else{
				res.push_back(right[j]);
				++j;
			}
		}
		while (i < left.size()){
			res.push_back(left[i]);
			++i;
		}
		while (j < right.size()){
			res.push_back(right[j]);
			++j;
		}
		return res;
	}
};

int main()
{
	Solution S;
	int n;
	vector<int> numbers;
	while (cin >> n)
		numbers.push_back(n);
	vector<int> arr = S.merge_sort(numbers);
	for (int i = 0; i < arr.size(); ++i){
		cout << arr[i] << " ";
	}
    cout << endl;
	system("pause");
	return 0;
}