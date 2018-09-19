#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool comp(int a, int b){
        string ab = "";
        string ba = "";
        ab += (to_string(a) + to_string(b));
        ba += (to_string(b) + to_string(a));
        return ab < ba;
    }
    string PrintMinNumber(vector<int> numbers) {
        string sum = "";
        sort(numbers.begin(), numbers.end(), comp);
        for (int i = 0; i < numbers.size(); ++i)
            sum += to_string(numbers[i]);
        return sum;
    }
/*
    string int2str(const int &int_tmp)
    {
        stringstream stream;
        stream << int_tmp;
        string string_tmp = stream.str();
        return string_tmp;
    }
*/
/*
    int str2int(const string &string_tmp)
    {
        int int_tmp;
        stringstream stream(string_tmp);
        stream >> int_tmp;
        return int_tmp;
    }
*/
};

int main()
{
    Solution S;
    int n;
    vector<int> numbers;
    while (cin >> n)
        numbers.push_back(n);
    string num_array = S.PrintMinNumber(numbers);
    cout << num_array << endl;
    system("pause");
    return 0;
}