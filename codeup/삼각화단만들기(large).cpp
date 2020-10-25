#include <iostream>
using namespace std;
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int c = n / 3; c <= n / 2; c++)
    {
        for (int a = 1; a <= n / 2; a++)
        {
            int b = n - (a + c);
            if (a + b > c && (c >= b && b >= a))
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}