#include <bits/stdc++.h>
using namespace std;

vector<char> dna = {'A','C','G','T'};
vector<bool> used(4,false);
unsigned long perm_len;

void explore(vector<char>& v, vector<int> &pos, unsigned long depth = 0){
    if(depth >= perm_len){
        for(int i = 0; i < pos.size(); i++) cout<<v[pos[i]];
        cout<<endl;
        return;
    }
    for(int i = 0; i < v.size(); i++){
        if(!used[i]){
            used[i] = true;
            pos[depth] = i;
            explore(v, pos, depth+1);
            used[i] = false;
        }
    }
    return;
}

int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        perm_len = k;
        vector<char> seq(n);
        vector<int> pos(perm_len,0);
        for(int i = 0; i < n; i++){
            cin>>seq[i];
        }
        explore(seq,pos);

    }
    return 0;
}