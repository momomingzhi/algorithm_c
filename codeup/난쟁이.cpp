#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int height[9];
    int sum = 0;
    bool breakPoint = false;
    for (int i = 0; i < 9; i++)
    {
        cin >> height[i];
        sum += height[i];
    }
    sort(height, height + 9);
    for (int i = 0; i < 9; i++)
    {
        if (breakPoint)
            break;
        for (int j = 0; j < 9; j++)
        {
            if (breakPoint)
                break;
            if (i != j)
            {
                if (sum - height[i] - height[j] == 100)
                {
                    for (int k = 0; k < 9; k++)
                    {
                        if (k != i && k != j)
                            cout << height[k] << endl;
                    }
                    breakPoint = true;
                }
            }
        }
    }
}
/*
dfs로 할 경우
int heigth[9];
bool check[9];
int sum = 0;
bool flag = false;
void dfs(int x){
    if(flag) return;
    if(x>=2){
        int checkSum = sum;
        for(int i=0;i<9;i++){
            if(check[i])
                checkSum -= heigth[i];
        }
        if(checkSum == 100){
            flag = true;
            for(int i=0;i<9;i++)
                if(!check[i])
                    cout<<heigth[i]<<endl;
        }
    }
    else{
        for(int i=0;i<9;i++){
            if(!check[i]){
                check[i] = true;
                dfs(x+1);
                check[i] = false;
            }
        }
    }
}
int main(){
    for (int i = 0; i < 9; i++)
    {
        cin >> heigth[i];
        sum += heigth[i];
    }
    sort(heigth, heigth + 9);
    dfs(0);
}

*/
// #include <stdio.h>
// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// int n, res;
// int ans[7];
// vector<int> arr;
// int dfs(int idx, int depth)
// {
//     if (res == 100)
//     {
//         printf("들어옴\n");
//         for (int i = 0; i < 7; i++)
//         {
//             cout << ans[i] << ' ';
//         }
//         cout << endl;
//         return 0;
//     }
//     if (idx == 6)
//     {
//         printf("res: %d\n", res);
//         res = 0;
//         return 0;
//     }
//     for (int i = idx; i < 9; i++)
//     {
//         printf("들어오오옴 %d %d \n", idx, depth);
//         ans[depth] = arr[i];
//         printf("ans[%d] = %d\n", depth, arr[i]);
//         res += arr[i];
//         dfs(idx + 1, depth + 1);
//     }
// }
// int main()
// {

//     printf("으으ddddd\n");
//     for (int i = 0; i < 9; i++)
//     {
//         int num;
//         cin >> num;
//         arr.push_back(num);
//     }
//     printf("으으\n");
//     sort(arr.begin(), arr.end());
//     for (int i = 0; i < 9; i++)
//         cout << arr[i] << ' ';
//     printf("\n아아아\n");
//     dfs(0, 0);
// }
