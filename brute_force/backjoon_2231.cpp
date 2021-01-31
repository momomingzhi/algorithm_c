#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
분해합
기본적인 브루트포스
while(part){
            sum += part%10;
            part= part/10;
}
이부분 4줄로 가능한데 멀리멀리 가다가 복잡해짐..
*/
int main(){
    int n;
    cin>>n;
    int sum,part;
    for(int i=1;i<n;i++){
        sum = i;
        part = i;
        while(part){
            sum += part%10;
            part= part/10;
        }
        if(n == sum){
            cout<< i <<endl;
            return 0;
        }
    }
    
    cout<< 0 <<endl;
}