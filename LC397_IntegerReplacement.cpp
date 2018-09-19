#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
	int integerReplacement(int n){
		if (n == INT_MAX)
			return 32;
		if (n <= 3)
			return n - 1;
		else if (n % 2 == 0)
			return integerReplacement(n / 2) + 1;
		else
			return min(integerReplacement(n - 1) + 1 , integerReplacement(n + 1) + 1);
			
	}
};

int main()
{
	int n;
	int x;
	Solution S;
	while (cin >> n){
		cout << S.integerReplacement(n) << endl;
	}
	return 0;

}