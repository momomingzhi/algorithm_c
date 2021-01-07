#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
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