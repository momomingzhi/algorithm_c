#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//dp로 풀었을때
int dp[3][1000] = {
    0,
};
int rgb[3][1000] = {
    0,
};
int main()
{
    int n; //집개수
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
    dp[0][0] = rgb[0][0];
    dp[1][0] = rgb[1][0];
    dp[2][0] = rgb[2][0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = min({dp[1][i - 1], dp[2][i - 1]}) + rgb[0][i];
        dp[1][i] = min({dp[0][i - 1], dp[2][i - 1]}) + rgb[1][i];
        dp[2][i] = min({dp[0][i - 1], dp[1][i - 1]}) + rgb[2][i];
    }
    cout << min({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]});
    return 0;
}
/*
dfs로 풀었을 때
int n;
int Min;
int arr[15][3];
bool color[3];
void dfs(int idx, int depth, int sum)
{
    //printf("first: arr[%d][%d] = %d sum:%d min:%d\n", depth, idx, arr[depth][idx], sum + arr[depth][idx], Min);
    if (depth != 0 && idx != 0)
    {
        if (sum + arr[depth][idx] > Min)
        {
            //printf("여기 들어와버림: %d > %d\n", sum + arr[depth][idx], Min);
            return;
        }
    }

    if (depth == n - 1)
    {

        if (Min > sum + arr[depth][idx])
            Min = sum + arr[depth][idx];
        //printf("second: arr[%d][%d] = %d sum:%d min:%d\n", depth, idx, arr[depth][idx], sum + arr[depth][idx], Min);
        return;
    }
    if (idx == 0)
    {
        dfs(idx + 1, depth + 1, sum + arr[depth][idx]);
        dfs(idx + 2, depth + 1, sum + arr[depth][idx]);
    }
    else if (idx == 1)
    {
        dfs(idx - 1, depth + 1, sum + arr[depth][idx]);
        dfs(idx + 1, depth + 1, sum + arr[depth][idx]);
    }
    else if (idx == 2)
    {
        dfs(idx - 1, depth + 1, sum + arr[depth][idx]);
        dfs(idx - 2, depth + 1, sum + arr[depth][idx]);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    Min = 100000000;
    if (n == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (Min > arr[0][i])
            {
                Min = arr[0][i];
            }
        }
    }
    else
    {
        for (int i = 0; i < 3; i++)
            dfs(i, 0, 0);
    }

    cout << Min << endl;
}
*/
