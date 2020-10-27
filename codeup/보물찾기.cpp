#include <stdio.h>
#include <algorithm>
#include<iostream>
using namespace std;
int main(){
    int n,k,tmp;
    cin>>n>>k;
    int arr[100001];
    int cnt = 0;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        tmp = arr[i];
        if(tmp>k){
            continue;
        }
        else if(tmp == k){
            cnt++;
            break;
        }
        else{
            for(int j=i+1;j<n;j++){
                tmp += arr[j];
                if(tmp == k){
                    cnt++;
                    break;
                }
                else if(tmp > k) break;
            }
        }
    }
    cout<<cnt<<endl;
}