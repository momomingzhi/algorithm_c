// #include<iostream>
// #include<queue>
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<algorithm>

// using namespace std;
// int N;
// int main(){
//     vector<int> v;
//     int half = 0;
//     cin>>N;
//     for(int i=1;i<=N;i++){
//         int x;
//         cin>>x;
//         v.push_back(x);
//         sort(v.begin(),v.end());
        
//         //for (std::vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
//     //std::cout << ' ' << *it;
//   //std::cout << '\n';
//         if(i%2==0){
//             //cout<<"짝수!!!!"<<endl;
//             //짝수일때
//             half = i/2;
//             printf("\n    %d  짝수일때 반: %d  %d\n",i,half,v[half-1]);
//             if(v[half-1]<v[half]){
//                 cout<<"짝수   "<<v[half]<<endl;
//             }
//         }
//         else{
//             //홀수일때
//             cout<<i<<"  홀수      "<<v[i/2]<<endl;
//         }
//     }
// }

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
 
int main(int argc, char *argv[])
{
	int n;
	int num;
	priority_queue<int, vector<int>, greater<int> > pqMax;
	priority_queue<int> pqMin;
 
	scanf("%d", &n);
 
	while (n--) {
		scanf("%d", &num);
 
		if (pqMin.empty() || pqMin.top() >= num) {
			pqMin.push(num);
            printf("\n   n: %d  min: %d %d\n",n,num,pqMin.top());
			if (pqMin.size() > pqMax.size() + 1) {
				pqMax.push(pqMin.top());
				pqMin.pop();
			}
		}
		else if (pqMax.empty() || pqMax.top() <= num) {
			pqMax.push(num);
            printf("\n   n:%d  max: %d %d\n",n,num,pqMax.top());
			if (pqMax.size() > pqMin.size()) {
				pqMin.push(pqMax.top());
				pqMax.pop();
			}
		}
		else if (pqMin.size() <= pqMax.size()) {
			pqMin.push(num);
		}
		else if (pqMin.size() > pqMax.size()) {
			pqMax.push(num);
		}
 
		printf("%d\n", pqMin.top());
	}
 
	return 0;
}
