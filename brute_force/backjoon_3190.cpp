#include<iostream>
#include<vector>
#include<deque>
using namespace std;
const int MAX = 100;

typedef struct{
    int y,x;
}Dir;

Dir moveDir[4] = {{0,1},{1,0},{0,-1},{-1,0}};
// 0,1 오른쪽으로
int N,K,L;
bool visited[MAX][MAX];
bool apple[MAX][MAX];

int main(){
    cin>>N>>K;
    for(int k=0;k<K;k++){
        int y,x;
        cin>>y>>x;
        apple[y-1][x-1] =true;
    }
    cin>>L;
    deque<pair<int,char>> turn;
    
    for(int l=0;l<L;l++){
        int X;
        char C;
        cin>>X>>C;
        turn.push_back({X,C});
    }
    int sec = 0;
    int idx = 0;
    deque<pair<int,int>> snake;
    snake.push_back({0,0});
    visited[0][0] = true;

    while(1){
        sec++;
        pair<int,int> before = snake.back(); //맨 마지막 원소 참조
        pair<int,int> cur = {before.first + moveDir[idx].y ,before.second + moveDir[idx].x};
        //뱀의 머리가 몸에 부딪히거나 범위 벗어날 경우
        if(visited[cur.first][cur.second] || !(0<=cur.first && cur.first<N && 0<=cur.second && cur.second <N)){
            cout<<sec<<endl;
            break;
        }
        visited[cur.first][cur.second] = true;
        snake.push_back(cur);

        //사과가 있는 위치면 꼬리 그대로
        if(apple[cur.first][cur.second])
            apple[cur.first][cur.second] = false;
        else{
            pair<int,int> tail = snake.front(); //첫번째 원소를 참조 한마디로 꼬리
            visited[tail.first][tail.second] = false;
            snake.pop_front(); //첫번째 원소를 제거
        }
        if(turn.size() && turn.front().first == sec){
            if(turn.front().second == 'L'){
                    idx = (idx + 3) % 4;
            }
            else{
                idx = (idx + 1) % 4;
            }
            turn.pop_front();
        }

    }
}