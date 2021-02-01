#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
부분 수열의 합
런타임 에러...
이 유형 자주 나옴 꼭 기억하기!!
*/
int n, s, sum, cnt;
int arr[20];
void dfs(int i, int sum)
{
    if (i == n)
        return;
    if (sum + arr[i] == s)
        cnt++;

    dfs(i + 1, sum);
    dfs(i + 1, sum + arr[i]);
}

int main()
{

    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    cnt = 0;
    dfs(0, 0);

    printf("%d\n", cnt);

    return 0;
}
/*
int arr[21];
int n, s, cnt = 0;
int solve(int depth, int sum)
{
    if (sum + arr[depth] == s)
    {
        cnt++;
        return 0;
    }
    if (depth == n - 1)
        return 0;

    solve(depth + 1, sum + arr[depth]);
}
int main()
{

    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (j == n)
                break;
            if (arr[i] + arr[j] == s)
            {
                cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (j == n)
                break;
            solve(j, sum);
            sum = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}
*/