#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,num;
    cin>>N;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<N;i++){
        cin>>num;
        if(!num && q.empty()){
            cout<<0<<"\n";
        }else if(!num){
                //0이 들어오면
                cout<<q.top()<<"\n";
                q.pop();
            }
        else{
            q.push(num);
        }
    }
}