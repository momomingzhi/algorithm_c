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