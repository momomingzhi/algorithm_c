#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include <queue> 
using namespace std;
int N,M;
int map[101][101],visitied[101][101];
queue<pair<int,pair<int,int>>> q;
int main(){
    cin>>M>>N;;
    for(int i = 0 ;i<N;i++){
        for(int j = 0;j<M;j++){
            cin>>map[i][j];
        }
    }
}