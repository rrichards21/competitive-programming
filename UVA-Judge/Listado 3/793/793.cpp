#include <bits/stdc++.h>
using namespace std;

class UnionFind{
    private:
        vector<int> p, rank;
    public:
        UnionFind(int N){
            rank.assign(N,0);
            p.assign(N,0);
            for(int i = 0; i < N; i++)
                p[i] = i;
        }
        int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
        bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}
        void unionSet(int i, int j){
            if(!isSameSet(i,j)){
                int x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]) p[y] = x;
                else{
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};


int main(){
    int c,N;
    cin>>c;
    string linea;
    for(int i = 0; i < c; i++){
        cin>>N;
        UnionFind uf(N+1);
        char q;
        int a,b, correct = 0, incorrect = 0;
        getline(cin,linea);
        while(getline(cin,linea), linea.compare("") != 0){
            stringstream ss(linea);
            ss>>q>>a>>b;
            if(q == 'c'){
                uf.unionSet(a,b);
            }
            else{
                uf.isSameSet(a,b) ? correct++ : incorrect++;
            }
        }
        cout<<correct<<","<<incorrect<<endl;
        if(i != c-1) cout<<endl;
        
    }
    return 0;
}