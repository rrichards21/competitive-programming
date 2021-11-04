#include <bits/stdc++.h>
using namespace std;

int maxBet(vector<int> &v, int n) {
    int curr_max = 0;
    int max_so_far = 0;
    for (int i = 0; i < n; i++) {
        curr_max = max(curr_max + v[i], 0);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main(){
    int n;
    while(cin >> n, n != 0){
        vector<int> bets(n);
        for(int i = 0; i < n; i++) cin >> bets[i];

        int bet = maxBet(bets, n);
        if(bet == 0) cout << "Losing streak." << endl;
        else cout << "The maximum winning streak is " << bet << "." << endl;
    }
    return 0;
}