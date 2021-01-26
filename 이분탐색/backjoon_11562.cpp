#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
#define ull unsigned long long
/*
문제를 제대로 이해 못함
최대로 밟을 수 있는 개수는 무조건 첫번쨰 징검다리부터 시작하는 것
1,2,3..n항
1,3,6,10 ...N 순서대로 뛰면 최대 개수 됨
등차수열의 공식 
징검다리 개수를 m개라 했을 때 m(m+1)/2 <=n 공식 만들 수 있엉
이 답을 찾기 위해 이분탐색 해줘야함
sqrt는 제곱근
*/
ull search(ull num)
{
    ull l = 1;
    ull r = sqrt(num) * 2;
    ull mid = 0;
    ull ans = 0;
    while (1 <= r)
    {
        mid = (l + r) / 2;
        if (mid * (mid + 1) <= 2 * num)

            ans = max(ans, mid),
            l = mid + 1;

        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ull t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << search(n) << endl;
    }
}