#include <cstdio> 
#include <string.h>
#include<iostream>
#include <queue>
using namespace std;
int N,M;
int map[1001][1001];
int visited[1001];
int cnt,len;
void dfs(int x){
    visited[x] = 1;
    for(int y=1;y<=N;y++){
        if(map[x][y]==1){
            if(!visited[y]){
                dfs(y);
            }
            
        }
    }
}
void bfs(int x){
    queue<int> q;
    visited[x] = 1;
    q.push(x);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i=1;i<=N;i++){
            if(map[current][i] && !visited[i]){
                visited[i] = 1; 
                q.push(i);
            }
        }

    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        len = max(y,len);
        map[x][y]=1;
        map[y][x]=1;
    }
    for(int i=1;i<=N;i++){
            if(!visited[i]){
                cnt++;
                bfs(i);
            }
    }
    cout<<cnt<<endl;
    
}
/*
생각하지 못한 부분
각 정점의 방문 여부 체크는 visited가 1차원배열인데 2차원으로 생각했다.
무방향 그래프이기 때문에 양쪽 정점 모두 연결

*/