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
        //Range Maximum Query
        int RMQ(int p, int L, int R, int i, int j){
            if(i > R || j < L) return -1;
            if(L >= i && R <= j) return st[p];

            int p1 = RMQ(left(p), L, (L+R)/2, i, j);
            int p2 = RMQ(right(p), (L+R)/2 +1, R, i, j);

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

        int RMQ(int i, int j){ return RMQ(1, 0, n-1, i, j);}
};

int main(){
    int N,a=0,b=1,c=1,d=0,num=1,den=1;
    cin>>N;
    string line;
    char path;
    getline(cin,line);
    for(int i = 0; i < N; i++){
        getline(cin,line);
        cout<<line<<endl;
        stringstream ss(line);
        while(ss>>path){
            cin>>path;
            if(path == 'R'){
                a = num; b = den;
            }
            else{
                c = num; d = den;
            }
            num = a + c;
            den = b + d;

        }
        cout<<num<<"/"<<den<<endl;
        a=0;b=1;c=1;d=0;num=1;den=1;

    }

    return 0;
}