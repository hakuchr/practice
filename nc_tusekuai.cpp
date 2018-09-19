// calc_s_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

double calc_s(int n, int m){
	if (n == 1){
		return m;
	}
	else if (n > 1){
		if (m == 1){
			return 0;
		}
		else if (m == 2){
			if (n / 2 * 2 < n){
				return 0;
			}
			else if (n / 2 * 2 == n){
				return 2;
			}
		}
			else if (m > 2){
				if (n == 2){
					return m * (m - 1);
				}else
				return m * pow(m - 1, n - 1) - calc_s(n - 1, m);
			}
		}
}

int main()
{
	int N, M, x;
	double S;
	cin >> N >> M;
	if (N < 1 | M < 1){
		cout << "wrong N or M" << endl;
	}
	else{
		S = calc_s(N, M);
		cout << S << endl;
	}
	cin >> x;
	return 0;
}
