#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
typedef unsigned long long int ull;
const int MAXLEN = 1e6;

// --------------------------------------------
// Rolling Hashing: double hash (extra safety)

struct RH_double { // rolling hashing
    static const ull B = 131; // base
    static const ull P[2]; // primes
    static ull pow[2][MAXLEN];    
    static ull add(ull x, ull y, int a) { return (x + y) % P[a]; }
    static ull mul(ull x, ull y, int a) { return (x * y) % P[a]; }
    static void init(int a) {
        pow[a][0] = 1;
        rep(i,1,MAXLEN) pow[a][i] =  mul(B, pow[a][i-1], a);
    }
    static void init() { init(0); init(1); }    
    vector<ull> h[2];
    int len;
    void init(vector<int>& s) {
        // for (int x : s) assert (x >= 1); // DEBUGGING
        len = s.size();
        rep(a,0,2) {
            h[a].resize(len);
            h[a][0] = s[0];
            rep(i,1,len) h[a][i] = add(mul(h[a][i-1], B, a), s[i], a);
        }
    }
    RH_double(vector<int>& s) { init(s); } // from vector<int>
    RH_double(string& s, char ref = 'a') { // from string
        vector<int> tmp; for (char c : s) tmp.push_back(c - ref + 1);
        init(tmp);
    }
    ull hash(int i, int j, int a) {
        if (i == 0) return h[a][j];
        return add(h[a][j], P[a] - mul(h[a][i-1], pow[a][j-i+1], a), a);
    }
    ull hash(int i, int j) { return hash(i,j,0) << 32 | hash(i,j,1); }
    ull hash() { return hash(0, len-1); }
};
// these lines are necessary for the code to compile
const ull RH_double::P[2] = {(ull)1e9+21, (ull)1e9+9};
ull RH_double::pow[2][MAXLEN];

int main(){
    RH_double::init();
    int N1, N2;
    int M1, M2;
    cin>>N1>>N2;
    string pat;
    vector<RH_double> pat_rh;
    char cmin = 'a';
    for(int i = 0; i < N1; i++){
        cin>>pat;
        RH_double rh(pat,cmin);
        pat_rh.push_back(rh);
    }
    cin>>M1>>M2;
    string txt;
    vector<RH_double> txt_rh;
    for(int i = 0; i < M1; i++){
        cin>>txt;
        RH_double rh(txt, cmin); // O(s.size())
        txt_rh.push_back(rh);
    }
    int k;
    bool found = false;
    for(int i = 0; i <= M1-N1; i++){
        for(int j = 0; j <= M2-N2; j++){
            k = 0;
            if(txt_rh[i].hash(j, j+N2-1) == pat_rh[k].hash(0,N2-1)){
                for(k = 1; k < N1; k++){
                    if(txt_rh[i+k].hash(j, j+N2-1) != pat_rh[k].hash(0,N2-1)){
                        found = true;
                        break;
                    }
                }
                if(k == N1){
                    found = true;
                    printf("(%d,%d) \n",i+1,j+1);
                }
            }
        }
    }
    if(!found) cout<<"NO MATCH FOUND..."<<endl;
    return 0;
}