#include <bits/stdc++.h>
using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

set<vector<int>> ans;
vector<int> s;
unsigned long perm_len;

void explore(int sum, vector<int>& v, vector<bool>& used, int curr_pos, unsigned long depth = 0){
    if(sum < 0 || depth >= perm_len+1){
        return;
    }
    if(sum == 0){
        ans.insert(s);
        return;
    }
    for(int i = curr_pos; i < v.size(); i++){
        if(!used[i]){
            used[i] = true;
            s.push_back(v[i]);
            explore(sum - v[i],v,used, i+1,depth+1);
            s.pop_back();
            used[i] = false;
        }
    }
    return;
}

int main(){
    int t,n;
    while(cin>>t>>n,n!=0){
        vector<int> x(n);
        for(int i = 0; i < n; i++){
            cin>>x[i];
        }
        vector<bool> used(n,false);
        perm_len = n;
        set<vector<int>> nset;
        ans = nset;
        explore(t,x,used,0);
        cout<<"Sums of "<<t<<":"<<endl;
        if(ans.size() == 0){
            cout<<"NONE"<<endl;
        }
        else{
            for(auto it = ans.rbegin(); it != ans.rend(); it++){
                for(int i = 0; i < it->size() ; i++){
                    cout<<(*it)[i];
                    if(i != it->size()-1) cout<<"+";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}