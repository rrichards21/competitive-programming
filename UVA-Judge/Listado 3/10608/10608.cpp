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
    int c,N,M,frnd1,frnd2;
    cin>>c;
    for(int i = 0; i < c; i++){
        cin>>N>>M;
        UnionFind uf(N+1);
        for(int j = 0; j < M; j++){
            cin>>frnd1>>frnd2;
            uf.unionSet(frnd1,frnd2);
        }
        int cont, max = 1;
        for(int j = 1; j <= N; j++){
            cont = 1;
            for(int k = j+1; k <= N; k++){
                if(uf.isSameSet(j,k)) cont++;
                if(cont > max) max = cont;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}