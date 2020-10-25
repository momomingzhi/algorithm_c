#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    for (int a = 1; a < N; a++)
    {
        for (int b = a; b < N; b++)
        {
            int c = N - (a + b);
            if (c < b)
                break;
            if (a + b > c)
                cnt++;
        }
    }
    cout << cnt << endl;
}