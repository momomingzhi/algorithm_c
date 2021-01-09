#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n, k, time[105][2], money[105][2];
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
    dfs(idx + 1, 0);
    dfs(idx + 1, 1);
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> time[i][0] >> money[i][0];
        cin >> time[i][1] >> money[i][1];
    }
}