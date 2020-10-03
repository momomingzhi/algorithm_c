#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int k;
int arr[14],depth[6];
void dfs(int idx,int cnt){
    if(cnt == 6){
        for(int i =0;i<6;i++){
            cout<<depth[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i=idx;i<k;i++){
        depth[cnt] = arr[i];
        dfs(i+1,cnt+1);
    }
}
int main(){
  while(1){
      cin>>k;
      if(k == 0) break;
      for(int i = 0;i<k;i++){
          cin>>arr[i];
      }
      dfs(0,0);
      cout<<endl;
  }
}