#include <stdio.h>
#include <algorithm>
#include<iostream>
using namespace std;
int main(){
    int a[2],b[2];
    cin>>a[0]>>a[1];
    cin>>b[0]>>b[1];
    sort(a,a+2);
    sort(b,b+2);
    if(b[0]>a[0] && b[0]<a[1]){
        if(b[1]>a[1])
            cout<<"cross"<<endl;
        else
            cout<<"not cross"<<endl;
    }
    else if(b[1]>a[0] && b[1]<a[1]){
        if(b[0]<a[0])
        cout<<"cross"<<endl;
        else
            cout<<"not cross"<<endl;
    }
    else cout<<"not cross"<<endl;
    }
    
