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
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]);
    cout << dp[n];
}
/*
n     n-1 n
ㅁ     ㅁ  ㅁ
ㅁ     ㅁ  ㅁ

n-1과 n-2에서 접근하는 2가지 방법 있다
dp[n] = dp[n-1] + dp[n-2] 식 세울 수 있음.
*/