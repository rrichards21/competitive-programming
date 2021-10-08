#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    private:
        vector<int> ft;
        int LSOne(int v){ return (v & (-v));}
    public:
        FenwickTree(int n){ ft.assign(n + 1, 0); }
        int rsq(int b) {
            int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
            return sum;
        }
        int rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a - 1));}
        void adjust(int k, int v) { for (; k < (int)ft.size(); k += LSOne(k)){ ft[k] += v;}}
        void printft(){
            for(int i = 0; i < ft.size(); i++){
                cout<<ft[i]<<" ";
            }
            cout<<endl;
        }
        void sumFreq(int i){
            ft[i] += 1;
        }
};


int main(){
    int N,val,k=1;
    string line;
    cin>>N;
    while(true){
        if(N != 0){
            FenwickTree ft(N);
            vector<int> prev(N+1);
            cout<<"Case "<<k<<":\n";
            k++;
            for(int i = 1; i <= N; i++){
                cin>>val;
                prev[i] = val;
                ft.adjust(i,val);
            }
            getline(cin,line);
            while(cin>>line, line != "END"){
                int ri,r;
                cin>>ri>>r;
                if(line == "S") {
                    ft.adjust(ri,r-prev[ri]);
                    prev[ri] = r;
                }
                else cout<<ft.rsq(ri,r)<<endl;
            }
        }
        cin>>N;
        if(N != 0) cout<<endl;
        else break;
    }
    return 0;
}