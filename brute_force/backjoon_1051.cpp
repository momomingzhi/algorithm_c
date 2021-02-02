#include <iostream>

#include <string>

#include <algorithm>

using namespace std;
/*
기본적인 브루트 포스 : 숫자 정사각형
문제 잘못읽음 정사각형인줄 몰랐다..
dfs로 해서 좀 더 에러 사항이 많았다
*/

const int MAX = 50;

int N, M;

int arr[MAX][MAX];

int solve()
{
    int result = 1; //길이가 1인 정사각형이 최소이기때문에
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 1; k < min(N, M); k++)
            {
                if (i + k < N && j + k < M && arr[i + k][j] == arr[i][j] && arr[i + k][j + k] == arr[i][j] && arr[i][j + k] == arr[i][j])
                {
                    result = max(result, k + 1);
                }
            }
        }
    }
    return result * result;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < M; j++)
        {
            arr[i][j] = temp[j] - 'O';
        }
    }
    cout << solve() << endl;
}

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n,m,cnt;
string box[51];
int solve(int index,int depth){
    int size = 0;
    printf("\n depth:%d\n",depth);
    if(depth == n || index == n){
            return 0;
    }
    for(int i=0;i<m;i++){
        printf("hey %d %d %d %d\n",index,i,depth,i+depth);
              //  printf("\n in box[%d][%d] = %c\n",index,i,box[index][i]);
              //  printf("\n in box[%d][%d] = %c\n",index,i+depth,box[index][i+depth]);
        printf("\n in box[%d][%d] = %c box[%d][%d] = %c box[%d][%d] = %c box[%d][%d] = %c \n",index,index,box[index][index],index,i+depth,box[index][i+depth],index+depth,index,box[index+depth][index],index+depth,i+depth,box[index+depth][i+depth]);
        if(i == m-1 || depth == n-1 || index == n-1){
            break;
        }
        if(box[index][index] == box[index][i+depth] == box[index+depth][index] == box[index+depth][i+depth]){
            size = (depth - i + 1) * (depth-index + 1);
            printf("************************size: %d\n",size);
            return size;
        }
    }
    solve(index,depth+1);
}
int main(){
    cin>>n>>m;
    int MAX = 0;
    for(int i=0;i<n;i++){
        cin>>box[i];
    }  
    for(int i=0;i<n;i++){
        solve(i,1);
        //MAX = max(MAX,solve(i,0));
    }  
    cout<<MAX<<endl;

}
*/