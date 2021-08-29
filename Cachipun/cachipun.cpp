#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<=b; i++)
typedef vector<int> vi;

int J, Q;

struct UnionFind {
    vi p, rank;
    UnionFind(int n) {
        rank.assign(n, 0);
        p.resize(n);
        rep(i,0,n-1) p[i] = i;
    }
    int findSet(int i) { return (i == p[i]) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x != y) {
            if (rank[x] < rank[y]) {
                p[x] = y;
            } else {
                p[y] = x;
                if (rank[y] == rank[x]) rank[x]++;
            }
        }
    }
};

int main() {
    scanf("%d%d",&J,&Q);
    UnionFind uf(J * 3);
    int discarded = 0;
    while (Q--) {
        int a, b, m; scanf("%d%d%d",&a,&b,&m);
        a--, b--;
        int a_moves[3] = {a * 3, a * 3 + 1, a * 3 + 2};
        int b_moves[3] = {b * 3, b * 3 + 1, b * 3 + 2};

        bool valid = true;
        for(int j=0; j<=2; j++){
            //(m+2)%3
            //m = 0 -> 2%3=2
            //m = 1 -> 3%3=0
            //m = 2 -> 4%3=1
            if (j == ((3 + m - 1) % 3)) continue;
            if (uf.isSameSet(b_moves[0], a_moves[j])) {
                valid = false; break;
            }
        }
        if (!valid) { discarded++; continue; }

        rep(j,0,2) {
            int bm = 3 * b + j; //3*2
            int am = 3 * a + ((3 + j + m - 1) % 3);
            uf.unionSet(am, bm);
        }
    }
    printf("%d\n", discarded);
    return 0;
}