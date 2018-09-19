#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int *cnt = new int[length]();
        for (int i = 0; i < length; ++i){
            if (cnt[numbers[i]] == 0)
                cnt[numbers[i]]++;
            else{
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution S;
    int length = 10, dd = -1;
    int *duplication = &dd;
    int numbers[length];
    for (int i = 0; i < 10; ++i)
        cin >> numbers[i];
    cout << S.duplicate(numbers, length, duplication) << ", " << *duplication << endl;
    system("pause");
    return 0;
}