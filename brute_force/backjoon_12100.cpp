#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
int arr[21][21];
int visited[21][21];
int dy[4] = {-1, 0, 1, 0}; //왼1  아래2   오르쪽3   위4
int dx[4] = {0, 1, 0, -1};
int solve(int dir)
{
    for (int i = 0; i < N; i++)
    {
        if (dir == 4)
        {
            //위
            if (!arr[0][i])
            {
                //0일 경우
            }
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
    }
}