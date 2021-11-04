/*
Autor: Rodrigo Richards
Scarecrow - 12405
rrichards - 958045
Código realizado por mí
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m,n!=0,m!=0){
        vector<int> heads(n), knights(m);
        for(int i = 0; i < n; i++){
            cin>>heads[i];
        }
        for(int i = 0; i < m; i++){
            cin>>knights[i];
        }
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());
        int cost = 0, chop = 0, c = 0;
        for(int i = 0; i < heads.size(); i++){
            for(int j = c; j < knights.size(); j++){
                if(heads[i] <= knights[j]){
                    cost += knights[j];
                    chop++;
                    c = j+1;
                    break;
                }
            }
        }
        if(chop != n){
            cout<<"Loowater is doomed!"<<endl;
        }
        else{
            cout<<cost<<endl;
        }
    }

    return 0;
}