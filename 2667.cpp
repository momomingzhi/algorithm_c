#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int N,total,cnt;
int map[26][26];
int visited[26][26];
vector <int> vec;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void dfs(int x,int y){
    visited[x][y] = 1;
    cnt++;
    for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
    if(map[nx][ny] ==1 && !visited[nx][ny]){
        
        dfs(nx,ny);

    }
}
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == 1 && !visited[i][j]){
                total++;
                cnt = 0; 
                dfs(i,j);
                vec.push_back(cnt);
                //printf("중간값: %d\n",cnt);
                
            }
            
        }
    }
    sort(vec.begin(), vec.end());
    cout<<vec.size()<<endl;
    for(int i = 0; i<vec.size();i++)
        cout<<vec[i]<<endl;
    //printf("total: %d\n",total);

}