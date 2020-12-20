#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, res;
int dfs(int total, int check)
{

    check--;
    if (total < n && check <= 0)
    {
        dfs(total + 1, 2);
    }
    if (total < n)
    {
        dfs(total + 1, check);
    }
    else if (total == n)
    {
        res++;
        return 0;
    }
}
int main()
{
    cin >> n;
    dfs(0, 0);
    cout << res << endl;
}