#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n, k;
int walk[10][2];
int bike[10][2];
int dfs(int idx, int sum)
{
    if (sum >= k)
    {

        return 0;
    }
    if (idx == n)
    {
        return 0;
    }
    //dfs()
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> walk[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> bike[i][j];
        }
    }
}