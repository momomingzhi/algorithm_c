#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
일곱 난쟁이
기본적인 브루트포스문제
*/
int main(){
    int arr[9];
    int sum = 0;
    int breakPoint = false;
    for(int i=0;i<9;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    //7 8 10 13 15 19 20 23 25
    sort(arr,arr+9); //sort
    for(int i=0;i<9;i++){
        if (breakPoint)
            break;
        for(int j=0;j<9;j++){
            
            if (breakPoint)
            break;
            if(i != j){
               if(sum - (arr[i] + arr[j]) == 100){
                    for(int k=0;k<9;k++){
                        if(k != i && k != j){
                            cout<<arr[k]<<endl;
                        } 
                    }
                    breakPoint = true;
               } 
            }
            
        }
    }



}