//在数字三角形中寻找一条路径，使得路径上的数字之和最大（递归实现）
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#define MAX 101


using namespace std;
int D[MAX][MAX];
int N;
int MaxSum(int r, int j){
	if (r == N)
		return D[r][j];
	else
		return max(MaxSum(r + 1, j), MaxSum(r + 1, j + 1)) + D[r][j];
}


int main(){
	int r, j;
	cin >> N;
	for (r = 1; r <= N; r++){
		for (j = 1; j <= r; j++){
			cin >> D[r][j];
		}
	}
	int x = MaxSum(1, 1);
	cout << x << endl;
	cin >> N;
	
	return 0;
}

/*测试用例：
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/
