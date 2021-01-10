#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//dfs로 풀었을떄
//가로를 2 새로를 1로 배치하는 아이디어
int dp[1000001];
int n;
int main()
{
    cin >> n;
    dp[1] = dp[2] = 0;
    dp[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 3]) % 100000007;
    }
    cout << dp[n];
}