#include <cstdio> 
#include <algorithm> 
#include<iostream>
#include <vector> 
#include <queue> 
using namespace std;
int T,M,N,K,x,y;
int map[51][51];
int visited[51][51];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
queue<pair<int,pair<int,int>>> q;
int main(){
    cin>>T>>M>>N>>K;
    for(int i=0;i<K;i++){
        cin>>y>>x;
        map[x][y]=1;
        q.push({0,{x,y}});
    }
    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        for(int i =0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx >=N || ny <0 || ny>=M)
                continue;
            if(map[nx][ny] ==1 && visited[nx][ny]){
                visited[nx][ny] = 1;
                q.push({cnt+1,{nx,ny}});
            }
            
        }
    }
}