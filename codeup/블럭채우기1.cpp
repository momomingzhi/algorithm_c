#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//dfs로 풀었을떄
//가로를 2 새로를 1로 배치하는 아이디어
int ans = 0;
void fillGrid(int idx, int len)
{
    if (idx > len)
        return;
    if (idx == len)
    {
        ans++;
        return;
    }
    fillGrid(idx + 1, len);
    fillGrid(idx + 2, len);
}
int main()
{
    int len;
    cin >> len;
    fillGrid(0, len);
    cout << ans << endl;
}

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