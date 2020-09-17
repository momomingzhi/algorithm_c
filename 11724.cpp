#include <cstdio> 
#include <string.h>
#include<iostream>
using namespace std;
int N,M;
int map[1001][499501];
int visited[1000][499500];
int cnt;
void bfs(int x){
    for(int y=1;y<=N;y++){
        if(map[x][y]==1 && !visited[x][y]){
            visited[x][y] = 1;
            bfs(y);
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        map[x][y]=1;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cnt++;
            visited[i][j] = 1;
            bfs(i);
        }
    }
    cout<<cnt<<endl;
    
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++){
    //         cout<<map[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
}