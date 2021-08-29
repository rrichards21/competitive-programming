#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
using namespace std;

class UF {
	private:
		vector<int> potencial, representante, rank;
		int nodos;
	public:
		UF(int N){
			nodos = N; potencial.assign(N, 0); representante.assign(N,0);
			rank.assign(N, 0); rep(i, N) representante[i] = i; 
		}
		
		int find(int x){
			if(representante[x] == x) return x;
			int rep = find(representante[x]);
			potencial[x] = (3 + potencial[x] + potencial[representante[x]])%3;
			representante[x] = rep;
			return rep;
		}
		
		void union_set(int x, int y, int edge){
			int rx = find(x), ry = find(y);
			potencial[ry] = (3 + edge + potencial[x] - potencial[y])%3;
			representante[ry] = rx;
		}
		
		int take_query(int a, int b, int m){
            //m = 0 -> 2%3=2
            //m = 1 -> 3%3=0
            //m = 2 -> 4%3=1
			m = (m + 2)%3;
			if(find(a) != find(b)){
				union_set(a, b, m);
				return 1;
			} else return (3 + potencial[b] - potencial[a])%3 == m;
		}
};

int main(){
	int J, Q; cin >> J >> Q;
	UF U(J);
	int ans = 0;
	rep(i,Q){
		int a,b,m; cin >> a >> b >> m;
		ans += (1 - U.take_query(a-1,b-1, m));
	}
	cout << ans << '\n';
	
return 0;}