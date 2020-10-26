
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> q;
    int N;
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    for(int i =0;i<N;i++){
        for(int j=0;j<N;j++){
            int x;
            cin>>x;
            if(q.size()<N){
                q.push(x);
            }
            else{
                if(q.top()<x){
                    q.pop();
                    q.push(x);
                }
            }
        }
        
    }
    cout<<q.top()<<endl;
    
 
    
}