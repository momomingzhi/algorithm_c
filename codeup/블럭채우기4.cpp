#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
dp[n-1] : 한개짜리의 경우
dp[n-2] : 3+1 하면 4가지의 경우가 나옴  dp[n-2] * 4
dp[n-3] : 3개짜리의 경우 왼, 오 2가지의 경우가 나옴 dp[n-3] * 2


*/
const int DIV = 100007;
int dp[10010];
;
int n;
int main()
{
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    for (int i = 4; i <= n; i++)
        dp[i] = (dp[i - 1] % DIV + dp[i - 2] * 4 % DIV + dp[i - 3] * 2 % DIV) % 100007;
    cout << dp[n];
}