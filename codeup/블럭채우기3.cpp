#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int dp[10010];
int n;
int main()
{
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 100007;
    cout << dp[n];
}