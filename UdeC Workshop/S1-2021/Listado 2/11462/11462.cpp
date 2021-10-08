#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, num;
    while(1){
        scanf("%d",&n);
        if(n == 0) break;
        vector<int> ages;
        for(int i = 0; i < n; i++){
            scanf("%d",&num);
            ages.push_back(num);
        }
        sort(ages.begin(), ages.end());
        for(int i = 0; i < n; i++){
            if(i == n-1){
              printf("%d\n",ages[i]);
            }
            else{
              printf("%d ",ages[i]);
            }
        }
    }
    return 0;
}