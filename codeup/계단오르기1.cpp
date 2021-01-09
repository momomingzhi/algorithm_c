#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n, res;
int dfs(int idx, int sum)
{
    if (sum == n)
    {
        res++;
        return 0;
    }
    if (idx == n)
    {
        return 0;
    }
    dfs(idx + 1, 1 + sum);
    dfs(idx + 1, 2 + sum);
}
int main()
{
    cin >> n;
    dfs(0, 0);
    cout << res << endl;
}