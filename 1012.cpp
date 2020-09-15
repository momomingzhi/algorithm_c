#include <cstdio> 
#include <string.h>
#include<iostream>
using namespace std;
int T, M, N, K;
int map[50][50];
int visited[50][50];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int bfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		if (map[nx][ny] && !visited[nx][ny]) {
			visited[nx][ny]++;
			bfs(nx, ny);
		}
	}
	return 0;
}
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
			map[i][j] = 0;
		}
	}
}
int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin>> M >> N >> K;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> y >> x;
			map[x][y] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					cnt++;
					visited[i][j]++;
					bfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
	
}