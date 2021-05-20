#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    private:
        vector<int> st, A;
        int n;
        int left(int p) { return p << 1;}
        int right(int p) { return (p << 1) + 1;}
        
        void build(int p, int L, int R){
            if(L == R) st[p] = R;
            else{
                build(left(p), L, (L+R)/2);
                build(right(p), (L+R)/2 + 1, R);
                int p1 = st[left(p)], p2 = st[right(p)];
                st[p] = (A[p1] >= A[p2]) ? p1 : p2;
            }
        }

        int rmq(int p, int L, int R, int i, int j){
            if(i > R || j < L) return -1;
            if(L >= i && R <= j) return st[p];

            int p1 = rmq(left(p), L, (L+R)/2, i, j);
            int p2 = rmq(right(p), (L+R)/2 +1, R, i, j);

            if(p1 == -1) return p2;
            if(p2 == -1) return p1;
            return (A[p1] >= A[p2]) ? p1 : p2;
        }
    
    public:
        SegmentTree(const vector<int> &_A){
            A = _A; n = (int)A.size();
            st.assign(4*n, 0);
            build(1, 0, n-1);
        }
        int rmq(int i, int j){ return rmq(1, 0, n-1, i, j);}
};

int main(){
    int n,q,a;
    while(cin>>n>>q, n != 0){
        vector<int> A(n+1);
        map<int,int> occ;
        for(int i = 0; i < n; i++){
            cin>>a;
            if(occ.find(a) == occ.end()) occ[a] = 0;
            occ[a]++;
        }
        for(auto it = occ.begin(); it != occ.end(); it++){
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;
        SegmentTree st(A);
        int i,j;
        for(int k = 0; k < q; k++){
            cin>>i>>j;
            // cout<<i<<","<<j<<endl;
            // cout<<A[st.rmq(i,j)]<<endl;
        }
    }

    return 0;
}