#include <iostream>
#include <math.h>
using namespace std;

int jumpFloor(int number) {
	if (number <= 0)
		return 0;
	if (number > 0 && number <= 2)
		return number;
	int i = number - 2; int j = 1;
	int methods = 1;
	int temp1 = 1;
	int temp2 = 1;
	while (i >= 0){
		for (int x = 1; x <= j; x++){
			temp1 = temp1 * (i + x);
			temp2 = temp2 * (j + 1 - x);
		}
		methods = methods + temp1 / temp2;
		temp1 = 1;
		temp2 = 1;
		i = i - 2;
		j++;
	}
	return methods;
}

int main(){
	int n;
	while (cin >> n){
		cout << jumpFloor(n) << endl;
	}
	return 0;

}