#include <bits/stdc++.h>
using namespace std;

class UnionFind{
    private:
        map<string,string> p;
        map<string,int> rank, cont;
    public:
        UnionFind(){}
        string findSet(string s){ 
            if(p.find(s) == p.end()) {
                p[s] = s;
                rank[s] = 0;
                cont[s] = 1;
                return s;
            }
            return (p[s] == s) ? s : (p[s] = findSet(p[s]));
        }
        bool isSameSet(string i, string j){ return findSet(i) == findSet(j);}
        void unionSet(string i, string j){
            if(!isSameSet(i,j)){
                string x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]){
                    p[y] = x;
                    cont[x] += cont[y];
                    cont[y]++;
                }
                else{
                    p[x] = y;
                    cont[y] += cont[x];
                    cont[x]++;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
        int getCont(string s){
            return cont[findSet(s)];
        }
};

int main(){
    int c,F;
    string frnd1,frnd2;
    cin>>c;
    for(int i = 0; i < c; i++){
        cin>>F;
        UnionFind uf;
        map<string,int> count;
        for(int j = 0; j < F; j++){
            cin>>frnd1>>frnd2;
            uf.unionSet(frnd1,frnd2);
            cout<<uf.getCont(frnd1)<<endl;
        }
    }
    return 0;
}