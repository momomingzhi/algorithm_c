#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
브루트 포스: 체스판 다시 칠하기
맨 처음 값 받을때 string으로 받았어야했는데 잘못 받음
사고과정은 맞았는데 구현하는 과정에서 복잡해짐
1. 모든 정점을 돌면서, 해당 정점이 8x8 크기의 판을 만들 수 있는 정점인지 ?
2. 가장 왼쪽 위의 좌표를 흰색으로 두었을 때 다시 칠해야 할 정사각형의 갯수가 몇개인지?
3. 가장 왼쪽 위의 좌표를 검은색으로 두었을 때 다시 칠해야 할 정사각형의 갯수가 몇개인지?

맨 처음 기준점 체스판을 만들어두고 비교하는 코드가 제일 깔끔했다
*/

const int INF = 987654321;
const int MAX = 50;
int M, N;
string board[MAX];
//(0, 0)이 W인 체스보드
string whiteFirst[8] = {

        { "WBWBWBWB" },

        { "BWBWBWBW" },

        { "WBWBWBWB" },

        { "BWBWBWBW" },

        { "WBWBWBWB" },

        { "BWBWBWBW" },

        { "WBWBWBWB" },

        { "BWBWBWBW" }

};
//(0, 0)이 B인 체스보드
string blackFirst[8] = {

        { "BWBWBWBW" },

        { "WBWBWBWB" },

        { "BWBWBWBW" },

        { "WBWBWBWB" },

        { "BWBWBWBW" },

        { "WBWBWBWB" },

        { "BWBWBWBW" },

        { "WBWBWBWB" }

};
//(0, 0)이 W인 체스보드 기준 바뀔 칸 수

int whiteFirstChange(int y, int x)

{

        int cnt = 0;

        for (int i = y; i < y + 8; i++)

                 for (int j = x; j < x + 8; j++)

                         if (board[i][j] != whiteFirst[i - y][j - x])

                                 cnt++;

 

        return cnt;

    /*
    y = 1로 넘어올때
    for(int i=1;i<9;i++)
    i = 1 whiteFirst[1 - 1][1 - 1] = whiteFirst[0][0]
    i = 2 whiteFirst[2 - 1][2 - 1] = whiteFirst[1][1]
    i = 3 whiteFirst[3 - 1][3 - 1] = whiteFirst[2][2]
    */

}
//(0, 0)이 B인 체스보드 기준 바뀔 칸 수

int blackFirstChange(int y, int x)

{

        int cnt = 0;

        for (int i = y; i < y + 8; i++)

                 for (int j = x; j < x + 8; j++)

                         if (board[i][j] != blackFirst[i - y][j - x])

                                 cnt++;

        return cnt;

}
int main(void)

{

        cin >> N >> M;

 

        for (int i = 0; i < N; i++)

                 cin >> board[i];

 

        int result = INF;

 
        /*
        N = 10 M = 13일때
        i는 2까지 가능 j는 5까지 가능

        */
        for (int i = 0; i + 7 < N; i++)

                 for (int j = 0; j + 7 < M; j++)
                    //8*8로 자르는 과정
                         result = min(result, min(whiteFirstChange(i, j), blackFirstChange(i, j)));

 

        cout << result << endl;

        return 0;

}

// #include <stdio.h>
// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;
// int n,m;
// char arr[51][51];

// int main(){
//     cin>>n>>m; //m이 가로
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<' ';

//         }
//         cout<<endl;
//     }
//     for(int i=0;i<n;i++){
//         for(int j=i;j<i+8;j++){
//             for(int k=0;k<m;k++){
//                 if(j ==0 ){
//                     //0열일때
//                     if(arr[j][k] == 'W'){
//                         if(arr[j][k+1] == 'W'){
//                              arr[j][k] == 'B';
//                              cnt++; 
//                         }

//                     }
//                     else if(arr[j][k] == 'B'){
//                         if(arr[j][k+1] == 'B'){
//                              arr[j][k] == 'W';
//                              cnt++; 
//                         }

//                     }
//                 }
//                 else{
//                     //0열 이상
//                     if(k == 0){
//                         //0행일떄
//                         if(arr[j-1][k] == 'W'){
//                             //위에꺼가 W일때 그 다음 열은 B여야함
//                             if(arr[j][k] == 'W'){
//                                 arr[j][k] == 'B';
//                                  cnt++; 
//                             }
//                         }
//                         else if(arr[j-1][k] == 'B'){
//                             if(arr[j][k] == 'B'){
//                                 arr[j][k] == 'W';
//                                  cnt++; 
//                             }
//                         }
//                     }
//                     else{
//                         //1행 1열부턴
//                         if(arr[j][k-1] == 'W'){
//                            if(arr[j][k] == 'W'){
//                                 arr[j][k] == 'B';
//                                  cnt++; 
//                             } 
//                         }
//                         else{
//                             if(arr[j][k] == 'B'){
//                                 arr[j][k] == 'W';
//                                  cnt++; 
//                             } 
//                         }
//                     }
                    
//                 }
                
                
//             }
//         }
//     }
//     cout<<cnt<<endl;
// }