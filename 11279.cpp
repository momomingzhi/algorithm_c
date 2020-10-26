#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    cin>>N;
    priority_queue<int> q; //우선순위 큐는 디폴트값이 내림차순 10 9 8 7 ...
    //priority_queue<int, vector<int>, greater<int> > q;	// 오름차순
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        if(!x&& q.empty()){
        
                cout<<0<<"\n";
        }
        else if(!x){
            cout<<q.top()<<"\n";
            q.pop();
        }
        else{
            q.push(x);
        }

    }
    return 0;
}