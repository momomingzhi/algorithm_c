#include <iostream>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    int N, M;
    int r, c, d;
    int map[51][51] = {0};
    int visited[51][51] = {0};

    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    while (true)
    {
        if (!visited[r][c])
        {
            cnt++;
            visited[r][c]++;
        }
        bool check = false;
        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4; //현재 위치에서 왼쪽 방향으로 회전
            int nr = r + dy[d];
            int nc = c + dx[d];

            if (nr < 0 || nr >= N || nc < 0 | nc >= M)
            {
                continue;
            }
            if (map[nr][nc] || visited[nr][nc])
                continue;
            check = true;
            r = nr;
            c = nc;
            break;
        }
        if (!check)
        {
            r = r + dy[(d + 2) % 4];
            c = c + dx[(d + 2) % 4];

            if (r < 0 || r >= N || c < 0 || c >= M || map[r][c])
                break;
        }
    }
    cout << cnt << endl;
}

// #include <stdio.h>
// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>
// using namespace std;
// int N, M;
// // vector<pair<int, int>> arr;
// int arr[4][51];
// int cnt;
// queue<pair<int, int>> moveInfo;
// int main()
// {
//     int x, y, dir = 0;
//     cin >> N >> M;
//     cin >> x >> y >> dir;
//     moveInfo.push({x, y});
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < M; j++)
//         {
//             int num, num2;
//             //cin >> num >> num2;
//             cin>>arr[i][j];
//             //arr.push_back({num, num2});
//         }
//     }
//     while (!moveInfo.empty())
//     {
//         //queue가 빌때까지
//         int x = moveInfo.front().first;
//         int y = moveInfo.front().second;
//         moveInfo.pop();
//         if (dir == 0)
//         {
//             //방향이 북쪽일때
//             if(arr[y-1][x] == 0){
//                 dir = 3;
//                 cnt++;

//                 moveInfo.push({y-1,x});
//             }
//         }
//         if (dir == 0)
//         {
//             //방향이 북쪽일때
//             if(arr[y-1][x] == 0){
//                 dir = 3;
//                 cnt++;

//                 moveInfo.push({y-1,x});
//             }
//         }
//         if (dir == 0)
//         {
//             //방향이 북쪽일때
//             if(arr[y-1][x] == 0){
//                 dir = 3;
//                 cnt++;
//                 arr[y-1][x] = 2; //청소했으니까
//                 moveInfo.push({x,y-1});
//             }else{
//                 //방향이 북쪽일때 이미 청소 되어있거나 벽이 경우
//                 moveInfo.push({x+1,y}); //방향 유지한채로 한칸 후진
//             }
//         }

//     }
// }