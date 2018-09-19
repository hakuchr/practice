#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int num = 0;
        int size = data.size();
        if (size < 2)
            return;
        for (int i = 0; i < size; ++i){
            num ^= data[i]; //所有数的异或结果
        }
        int flag = 0; //标志位，记录异或结果中等于1的最低位的位置
        while((num&1) == 0){
            num = num >> 1;
            ++flag;
        }
        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < size; ++i){ //再次遍历数组
            if ((data[i] & (1 << flag)) == 0){ //根据标志位是否为0分为两组
                *num1 ^= data[i]; //相同的数会分到同一组，落单的数分别在两组，分别对两组所有数求异或
            }else{
                *num2 ^= data[i];
            }
        }
    }
};

int main()
{
    Solution S;
    int n , n1 = 0, n2 = 0;
    int *num1 = &n1, *num2 = &n2;
    vector<int> numbers;
    while (cin >> n)
        numbers.push_back(n);
    S.FindNumsAppearOnce(numbers, num1, num2);
    cout << *num1 << ", " << *num2 << endl;
    system("pause");
    return 0;
}

//test: 2 5 5 1 4 2 9 4 3 3 6 3 3 6 7 9 8 8
// 4 6 2 2 3 3 8 8 9 9 1000000 1000000

//https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking