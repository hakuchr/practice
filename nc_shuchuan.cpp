#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int num[N];
    int sort[N];
    int count[N];
    for (int n = 0; n < N; n++)
    {
        cin >> num[n];
        sort[n] = num[n];
        count[n] = 1;
        while(sort[n] / 1000 == 0)
        {
            sort[n] = sort[n] * 10;
            count[n] = count[n] * 10;
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - 1 - i; j++)
        {
            if(sort[j] < sort[j + 1])
            {
                int temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
                int temp_c = count[j];
                count[j] = count[j + 1];
                count[j + 1] = temp_c;
            }
        }
    }
    
    for(int n = 0; n < N; n++)
    {
        cout << sort[n] / count[n];
    }
    return 0;
}