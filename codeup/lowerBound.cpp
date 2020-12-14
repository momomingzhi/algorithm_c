#include <stdio.h>
#include <algorithm>
#include<iostream>
using namespace std;
int main(){
    int n,k,tmp = 0;
    int arr[100001];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(k<=arr[i]){
            tmp = i+1;
            break;
        }
    }
    if(tmp) cout<<tmp <<endl;
    else 
        cout<<n+1<<endl;
}