#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int arr[4] = {0, 1, 2, 3};
int n;
int cnt, res;
int dfs(int total, int check3)
{
    check3 -= 1;
    if (n - total >= 1)
    {
        //printf("%d ", 1);
        dfs(total + 1, check3);
    }

    if (n - total >= 2)
    {
        //printf("%d ", 2);
        dfs(total + 2, check3);
    }

    if (n - total >= 3 && check3 <= 0)
    {
        //printf("%d ", 3);
        dfs(total + 3, 3);
    }

    else if (total == n)
    {
        //printf("\n");
        res += 1;
    }
}
int main()
{
    cin >> n;
    dfs(0, 0);
    cout << res << endl;
}