#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int city[10001];
/*
2512 예산
예를 들어, 전체 국가예산이 485이고 4개 지방의 예산요청이 각각 120, 110, 140, 150이라고 하자. 이 경우, 상한액을 127로 잡으면, 위의 요청들에 대해서 각각 120, 110, 127, 127을 배정하고 그 합이 484로 가능한 최대가 된다. 

여러 지방의 예산요청과 국가예산의 총액이 주어졌을 때, 위의 조건을 모두 만족하도록 예산을 배정하는 프로그램을 작성하시오.

first를 제일 작은 숫자로 했는데 0으로 해야했음

*/
int main()
{
    int n, m;
    int first = 100000000000;
    int last = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> city[i];
        if (last < city[i])
        {
            last = city[i];
        }
    }
    first = 0;
    cin >> m;
    int res, sum = 0;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid < city[i])
            {
                sum += mid;
            }
            else
            {
                sum += city[i];
            }
        }
        if (sum > m)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
            res = mid;
        }
    }
    cout << res << endl;
}