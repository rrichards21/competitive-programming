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
                if(A[R] < 0) st[p] = -1;
                else if(A[R] == 0) st[p] = 0;
                else st[p] = 1;
            }
            else{
                build(left(p), L, (L+R)/2);
                build(right(p), (L+R)/2 + 1, R);
                int p1 = st[left(p)], p2 = st[right(p)];
                cout<<"p1: "<<p1<<" p2: "<<p2<<endl;
                if(p1*p2 < 0) st[p] = -1;
                else if(p1*p2 == 0) st[p] = 0;
                else st[p] = 1;
            }
        }

        int rmq(int p, int L, int R, int i, int j){
            if(i > R || j < L) return 1;
            if(L >= i && R <= j) return st[p];

            int p1 = rmq(left(p), L, (L+R)/2, i, j);
            int p2 = rmq(right(p), (L+R)/2 +1, R, i, j);

            if(p1 == -1) return p2;
            if(p2 == -1) return p1;
            return p1*p2;
        }
        void update(int p, int V, int L, int R){
            if(L == R){
                if(V < 0) st[p] = -1;
                else if(V == 0) st[p] = 0;
                else st[p] = 1;
            }
            else{
                build(left(p), L, (L+R)/2);
                build(right(p), (L+R)/2 + 1, R);
                int p1 = st[left(p)], p2 = st[right(p)];
                if(p1*p2 < 0) st[p] = -1;
                else if(p1*p2 == 0) st[p] = 0;
                else st[p] = 1;
            }
        }
    
    public:
        SegmentTree(const vector<int> &_A){
            A = _A; n = (int)A.size();
            st.assign(4*n, 0);
            build(1, 0, n-1);
        }
        int rmq(int i, int j){ return rmq(1, 0, n-1, i, j);}
        void printst(){
            for(int i = 0; i <= 7; i++){
                cout<<st[i]<<" ";
            }
            cout<<endl;
        }
        void preorder(int p){
            if(p < 0 || p > 8) return;
            cout<<st[p]<<" ";
            preorder(left(p));
            preorder(right(p));
        }
        void update(int i, int V){
            update(i,V,i,i);
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
                st.preorder(N/2-1);
                cout<<endl;
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