#include <cstdio> 
#include <algorithm> 
#include<iostream>
#include <vector> 
#include <queue> 
using namespace std;
int M,N,H;
const int MAX = 101;
int map[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};
queue<pair<int,pair<int,int>>> q;
int main(){
    cin>>M>>N>>H;
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int z=0;z<M;z++){
                cin>>map[i][j][z];
                if(map[i][j][z]){
                    q.push(make_pair(i,make_pair(j,z)));
                }
            }
        }
    }
    while(!q.empty()){
        int z = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        for(int i =0 ;i<6;i++){
            int nz = z + dz[i], nx = x + dx[i], ny = y + dy[i];
            if(nz<0 || nz>=H || nx<0 || nx>=N || ny<0 || ny>=M)
                continue;
            visited[nz][nx][ny] = visited[z][x][y] +1;
                q.push({nz,{nx,ny}});
        }
    }
    int res;
     for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int z=0;z<M;z++){
                if(visited[i][j][z]==-1){
                    cout<<-1;
                    return 0;
                }
                res = max(res,visited[i][j][z]);
            }
        }
     }
     cout<<res;
     
}