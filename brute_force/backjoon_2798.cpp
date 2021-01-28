#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
블랙잭
기본적인 브루트포스문제
*/
int arr[101];
int n, m;
int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    int MaxSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (i == n - 1)
                    break;
                sum += arr[i] + arr[j] + arr[k];
                if (MaxSum < sum && sum <= m)
                {
                    MaxSum = sum;
                }
                sum = 0;
            }
        }
    }
    cout << MaxSum << endl;
}