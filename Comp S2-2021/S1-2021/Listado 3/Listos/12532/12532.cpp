#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    private:
        vector<int> st, A;
        int n;
        int left(int p) { return p << 1;}
        int right(int p) { return (p << 1) + 1;}
        
        void build(int p, int L, int R){
            if(L == R){
                if(A[R] == 0) st[p] = 0;
                else if(A[R] < 0) st[p] = -1;
                else st[p] = 1;
            }
            else{
                build(left(p), L, (L+R)/2);
                build(right(p), ((L+R)/2) + 1, R);
                int p1 = st[left(p)], p2 = st[right(p)];
                if(p1*p2 == 0) st[p] = 0;
                else if(p1*p2 < 0) st[p] = -1;
                else st[p] = 1;
            }
        }

        int rmq(int p, int L, int R, int i, int j){
            if(j < L || R < i) return -2;
            if(i <= L && R <= j) return st[p];
            int p1 = rmq(left(p), L, (L+R)/2, i, j);
            int p2 = rmq(right(p), ((L+R)/2) +1, R, i, j);
            if(p1 == -2) return p2;
            if(p2 == -2) return p1;
            return p1*p2;
        }
        int update(int i, int V, int L, int R, int p){
            if(i < L || i > R) return st[p];
            if(L == R && L == i){
                if(V == 0) st[p] = 0;
                else if(V < 0) st[p] = -1;
                else st[p] = 1;
                return st[p];
            }
            else{
                update(i,V, L, (L+R)/2,left(p));
                update(i,V, ((L+R)/2) + 1, R, right(p));
                int p1 = st[left(p)], p2 = st[right(p)];
                if(p1*p2 == 0) st[p] = 0;
                else if(p1*p2 < 0) st[p] = -1;
                else st[p] = 1;
                return st[p];
            }
        }
    
    public:
        SegmentTree(const vector<int> &_A){
            A = _A; n = (int)A.size();
            st.assign(4*n, 0);
            build(1, 0, n-1);
        }
        int rmq(int i, int j){ return rmq(1, 0, n-1, i, j);}
        void update(int i, int V){
            update(i,V,0,n-1,1);
        }
};

int main(){
    int N,K,I,V;
    int val;
    char cmd;
    while(cin>>N>>K){
        vector<int> vec(N);
        for(int i = 0; i < N; i++){
            cin>>vec[i];
        }
        SegmentTree st(vec);
        for(int i = 0; i < K; i++){
            cin>>cmd>>I>>V;
            if(cmd == 'C'){
                st.update(I-1,V);
            }
            else{
                int ans = st.rmq(I-1,V-1);
                if(ans > 0) cout<<"+";
                else if(ans < 0) cout<<"-";
                else cout<<"0";
            }
        }
        cout<<endl;
    }
    return 0;
}