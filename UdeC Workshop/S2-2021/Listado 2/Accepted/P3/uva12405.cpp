/*
Autor: Rodrigo Richards
Scarecrow - 12405
rrichards - 958045
Código realizado por mí
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int c = 1; c <= t; c++){
        cin>>n;
        vector<char> field(n);
        vector<bool> mark(n,false);
        for(int i = 0; i < n; i++){
            cin>>field[i];
            if(field[i] == '#') mark[i] = true;
        }
        int sc = 0;
        for(int i = 1; i < n; i++){
            if(i == n-1 && !mark[i-1]){
                mark[i-1] = true;
                mark[i] = true;
                sc++;
                break;
            }
            else if(i == n-1 && mark[i-1]) break;
            if(!mark[i-1] && !mark[i+1]){
                mark[i-1] = true;
                mark[i] = true;
                mark[i+1] = true;
                i += 2;
                sc++;
                continue;
            }
            if(!mark[i-1] && mark[i+1]){
                mark[i-1] = true;
                mark[i] = true;
                mark[i+1] = true;
                sc++;
                continue;
            }
            if(mark[i-1] && !mark[i+1] && field[i] == '.' && field[i-1] == '.'){
                mark[i-1] = true;
                mark[i] = true;
                mark[i+1] = true;
                i += 2;
                sc++;
                continue;
            }
        }
        if(!mark[n-1]) sc++;
        cout<<"Case "<<c<<": "<<sc<<endl;
    }

    return 0;
}