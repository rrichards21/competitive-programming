#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string line;
    while(cin>>N, N != 0){
        vector<int> resistances(N+1);
        for(int i = 0; i < N; i++){
            cin>>resistances[i];
        }
        getline(cin,line);
        while(cin>>line, line != "END"){
            int ri,r;
            cin>>ri>>r;
        }
    }

    return 0;
}