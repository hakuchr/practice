
#include <iostream>
#include <string>
using namespace std;

bool str2num(string s, double &x){
	x = 0;
	string::iterator iter;
	int cnt = 0;
	int dot = 0;
	int cnt_d = 1;
	int sign = 1;
	for (iter = s.begin(); iter != s.end(); ++iter){
		int tmp = int(*iter);
		if (tmp < 45 || tmp == 47 || tmp >57)
			return false;
		if (tmp == 45){
			sign = -1;
			continue;
		}
		if (tmp == 46){
			dot++;
			if (dot > 1)
				return false;
			continue;
		}
		if (dot == 1){
			cnt_d = cnt_d * 10;
			x = x + double(tmp - 48) / cnt_d;
		}
		else{
			x = x * 10 + double(tmp - 48);
			cnt++;
		}
	}
	x = sign * x;
	return true;
}

int main()
{
	string sx, sy, sz;
	cin >> sx >> sy;
	if (sx.empty() || sy.empty())
		return false;
	double x = 0;
	double y = 0;
	double z = 0;
	bool isNum_x = str2num(sx, x);
	bool isNum_y = str2num(sy, y);
	if (!isNum_x || !isNum_y)
		return false;
	z = x + y;
	cout << z << endl;
	return 0;
}
//阿里2018笔试；输入两个用string表示的数，输出两数之和