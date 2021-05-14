#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    char action;
    while(scanf("%d",&N), N != 0){
        cout<<N<<endl;
        vector<int> resistances(N+1);
        for(int i = 0; i < N; i++){
            cin>>resistances[i];
            cout<<resistances[i]<<endl;
        }
        while(scanf("%c",&action), action != 'E'){
            int ri, r;
            scanf("%d%d",&ri,&r);
            cout<<action<<" "<<ri<<" "<<r<<endl;
        }
    }

    return 0;
}