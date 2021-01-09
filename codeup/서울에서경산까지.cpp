#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n, k, times[105][2], money[105][2], maxMoney;
int dfs(int idx, int _time, int _money)
{
    if (_time > k)
    {

        return 0;
    }
    if (idx == n + 1)
    {
        if (_money > maxMoney)
        {
            maxMoney = _money;
        }
        return 0;
    }
    if (times[idx - 1][0] < times[idx - 1][1] && money[idx - 1][0] > money[idx - 1][1])
    {
        //도보로 가면 무조건 이득
        dfs(idx + 1, times[idx - 1][0] + _time, money[idx - 1][0] + _money);
    }
    else if (times[idx - 1][0] > times[idx - 1][1] && money[idx - 1][0] < money[idx - 1][1])
    {
        //자전거로 가면 무조건 이득
        dfs(idx + 1, times[idx - 1][1] + _time, money[idx - 1][1] + _money);
    }
    else
    {
        //비교 불가일때s
        dfs(idx + 1, times[idx - 1][0] + _time, money[idx - 1][0] + _money);
        dfs(idx + 1, times[idx - 1][1] + _time, money[idx - 1][1] + _money);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> times[i][0] >> money[i][0];
        cin >> times[i][1] >> money[i][1];
    }
    dfs(1, 0, 0);
    cout << maxMoney << endl;
}