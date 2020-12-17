#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int f(int n)
{
    if (n == 1)
        return 1;
    else
    {
        return n * f(n - 1);
    }
}
int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> com(k, 0);
    for (int i = 0; i < n; i++)
        com[i] = 1;
    sort(com.begin(), com.end());
    int res = 0;
    do
    {
        res++;
    } while (next_permutation(com.begin(), com.end()));
    cout << res;
    //cout << f(k) / (f(n) * f(k - n)) << endl;
}
/* 
오름 차순으로 정렬된 값을 가진 컨테이너로만 사용 가능
중복이 있는 원소들은 중복을 제외하고 순열 만들어줌
{0,0,1}과 같은 배열의 순열을 구한다면 중복을 제외한 (0,0,1) {0,1,0} {1,0,0}
예시 {1,2,3,4} 에서 2개의 원소를 고르는 모든 경우의 수 출력
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    vector<int> s{ 1, 2, 3, 4 };
    vector<int> temp{ 1, 1, 0, 0 };
 
    do {
        for (int i = 0; i < s.size(); ++i) {
            if (temp[i] == 1)
                cout << s[i] << ' ';
        }
        cout << endl;
    } while (prev_permutation(temp.begin(), temp.end()));
}


출처: https://mjmjmj98.tistory.com/38 [코딩 공부]
*/