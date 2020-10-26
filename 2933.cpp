#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
char map[101][101];
int bet[101];
int main(){
    int R,C,N;
    cin>>R>>C;
    string str;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>map[i][j];
        }

    }
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>bet[i];
    }
}