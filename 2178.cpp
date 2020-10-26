// #include<iostream>
// #include<vector>
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<math.h>
// #include<algorithm>
// #include <queue> 
// using namespace std;
// int N,M;
// int map[101][101],visitied[101][101];
// int dy[4] = { 1,-1,0,0 };
// int dx[4] = { 0,0,1,-1 };
// queue<pair<int,pair<int,int>>> q;
// int main(){
//     cin>>N>>M;;
//     for(int i = 0 ;i<N;i++){
//         for(int j = 0;j<M;j++){
//             cin>>map[i][j];
//         }
//     }
    
//     q.push({0,{0,0}});
//     while(!q.empty()){
//         int x = q.front().second.first;
//         int y = q.front().second.second;
//         int cnt = q.front().first;
//         q.pop();
//         visitied[x][y] = 1;

//         for(int i = 0;i<4;i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if(nx <0 || nx>N || ny < 0 || ny > M) continue;
//             if(map[nx][ny] == 1 && visitied[nx][ny] == 0){
//                 q.push({cnt+1,{nx,ny}});
//             }
//         }
//     }
//     // for(int i = 0; i<N;i++){
//     //     for(int j=0;j<M;j++){
//     //         cout<<map[i][j]<<' ';
//     //     }
//     //     cout<<endl;
//     // }
// }
#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX 100

int N, M;
int arr[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { false, };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int x, int y, int cnt) {
	queue <pair <pair <int, int>, int>> que;
	que.push(make_pair(make_pair(x, y), cnt));

	while (!que.empty()) {
		x = que.front().first.first;
		y = que.front().first.second;
		cnt = que.front().second;
		que.pop();
        visit[x][y] = true;
		if (x == N - 1 && y == M - 1) return cnt;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (arr[nx][ny] == 1 && !visit[nx][ny]) {
				//visit[nx][ny] = true;
				que.push(make_pair(make_pair(nx, ny), cnt + 1));
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)	arr[i][j] = temp[j] - '0';
	}
	visit[0][0] = true;
	cout << bfs(0, 0, 1) << endl;
	return 0;
}