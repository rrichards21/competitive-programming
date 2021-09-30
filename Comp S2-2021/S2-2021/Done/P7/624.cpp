#include <bits/stdc++.h>
using namespace std;

vector<int> curr_best,pos;
int best_sum;
int perm_len;
int best_len;

void explore(int sum, vector<int>& v, vector<int>& pos, vector<bool>& used, unsigned long depth,int curr_pos = 0){
    if(sum < best_sum && sum >= 0){
        best_sum = sum;
        curr_best = pos;
        best_len = depth;
    }
    if(depth >= perm_len || sum < 0){
        return;
    }
    for(int i = curr_pos; i < v.size(); i++){
        if(!used[i]){
            used[i] = true;
            pos[depth] = i;
            explore(sum - v[i],v,pos,used,depth+1, i+1);
            used[i] = false;
        }
    }
    return;
}

int main(){
    string line;
    while(getline(cin,line)){
        stringstream ss(line);
        int sum,n;
        ss>>sum>>n;
        perm_len = n;
        vector<int> tracks(n);
        vector<int> positions(perm_len,0);
        vector<bool> used(n,false);
        for(int i = 0; i < n; i++){
            ss>>tracks[i];
        }
        best_sum = 9999;
        explore(sum,tracks,positions,used,0);
        int curr_sum = 0;
        for(int i = 0; i < best_len; i++){
            cout<<tracks[curr_best[i]]<<" ";
            curr_sum += tracks[curr_best[i]];
        }
        cout<<"sum:"<<curr_sum<<endl;
    }

    return 0;
}