#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
const int MAX = 20;
int N;
int board[MAX][MAX];
int maxBlock;
int shift(int type){
    queue<int> q;
    switch(type){
        //왼쪽
        case 0:
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(board[i][j])
                        q.push(board[i][j]);
                    else
                        board[i][j] = 0;
                }
                int idx = 0;
                while(!q.empty()){
                    int data = q.front();
                    q.pop();
                    if(board[i][idx]==0){
                        
                    }
                }
            }
            
    }
}
int DFS(int cnt){
    if(cnt == 5){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                maxBlock = max(maxBlock,board[i][j]);
            }
        }
    }
    int copyBoard[MAX][MAX];
    //현 보드상태 저장
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            copyBoard[i][j] = board[i][j];
        }
    }
    for(int i=0;i<4;i++){
        shift(i);
    }

}
int main(void)

{

        cin >> N;

 

        for (int i = 0; i < N; i++)

                 for (int j = 0; j < N; j++)

                         cin >> board[i][j];

 

        DFS(0);

        cout << maxBlock << endl;

        return 0;

}
// int N;
// int arr[21][21];
// int visited[21][21];
// int dy[4] = {-1, 0, 1, 0}; //왼1  아래2   오르쪽3   위4
// int dx[4] = {0, 1, 0, -1};
// queue <pair<int,int>> q;
// int solve(int dir)
// {
//     for (int i = 0; i < N; i++)
//     {
//         for(int j=0;j<N;j++){
//             if(arr[i][j]){
//                 q.push({i,j});
//             }
//         }
//     }
// }
// int main()
// {
//     cin >> N;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     for (int i = 0; i < 4; i++)
//     {
//     }
// }