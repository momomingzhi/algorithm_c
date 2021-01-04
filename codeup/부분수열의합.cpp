#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, s, sum, res;
int arr[20];
void dfs(int i, int sum)
{
    if (i == n)
        return;
    if (sum + arr[i] == s)
        res++;
    dfs(i + 1, sum);          //현재 가르키고 있는 수를 더하는 경우
    dfs(i + 1, sum + arr[i]); // 그러지 않고 다음 index로 건너 뛰는 경우
}
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dfs(0, 0);
    cout << res << endl;
}
/*
int n, s, sum, res;
int arr[21];
void dfs(int x, int depth)
{

    if (sum == s)
    {
        res++;
        return;
    }
    if (x == depth)
    {
        printf("depth에 들어옴 x:%d depth:%d\n");
        sum = 0;
        return;
    }
    for (int i = x; i < n; i++)
    {
        sum += arr[i];

        printf("i:%d x:%d arr:%d sum:%d depth:%d\n", i, x, arr[i], sum, depth);
        dfs(i + 1, depth);
    }
}
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // sort(arr, arr + n);
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << ' ';
    for (int i = 2; i < n; i++)
        dfs(0, i);
    cout << res << endl;
}
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
int n, s, sum, res;
int arr[21];
void dfs(int x, int depth)
{

    if (sum == s)
    {
        res++;
        return;
    }
    if (x == depth)
    {
        printf("depth에 들어옴 x:%d depth:%d\n");
        sum = 0;
        return;
    }
    for (int i = x; i < n; i++)
    {
        sum += arr[i];

        printf("i:%d x:%d arr:%d sum:%d depth:%d\n", i, x, arr[i], sum, depth);
        dfs(i + 1, depth);
    }
}
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // sort(arr, arr + n);
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << ' ';
    for (int i = 2; i < n; i++)
        dfs(0, i);
    cout << res << endl;
}


*/