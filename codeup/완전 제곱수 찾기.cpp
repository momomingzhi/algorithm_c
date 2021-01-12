#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, k, res;
int arr[11];
int search(int num, int first, int last, int flag)
{
    printf("아아아: %d %d %d 완전제곱:%d\n", num, first, last, (num / 2) * (num / 2));
    if (num / 2 * num / 2 == num)
    {
        cout << num << endl;
        return 0;
    }
    int middle = (first + last) / 2;
    if (middle * middle <= num && (middle + 1) * (middle + 1) > num)
    {
        cout << middle * middle << endl;
        return 0;
    }
    if (middle * middle > num)
    {

        search(num, first, middle, 1);
    }
    else if (middle * middle <= num)
    {

        search(num, middle, last, 0);
    }
}
int main()
{

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        search(arr[i], 1, arr[i], 1);
    }
}