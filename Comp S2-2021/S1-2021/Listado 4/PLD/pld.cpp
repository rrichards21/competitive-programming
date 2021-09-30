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
    int n;
    string s;
    cin>>n>>s;
    string rs = s;
    reverse(rs.begin(),rs.end());
    char cmin = *min_element(s.begin(), s.end());
    RH_double rh_original(s,cmin);
    RH_double rh_reversed(rs,cmin);
    int match = 0;
    for(int i = 0; i <= s.size()-n; i++){
        // cout<<i<<" "<<i+n-1<<"     "<<s.size()-n-i<<" "<<s.size()-i-1<<endl;
        ull rh1 = rh_original.hash(i,i+n-1);
        ull rh2 = rh_reversed.hash(s.size()-n-i,s.size()-i-1);
        if(rh1 == rh2){
            match++;
        }
    }
    cout<<match<<endl;
    return 0;
}

//ababab
//bababa

// 0 2     3 5
// 1 3     2 4
// 2 4     1 3
// 3 5     0 2
