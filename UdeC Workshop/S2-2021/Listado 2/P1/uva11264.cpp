#include <bits/stdc++.h>
using namespace std;

set<long int> used_c;

void withdraw(long int x, vector<long int> coins, int curr_coin){
    if(x <= 0) return;
    long int y = -999999999;
    for(int i = coins.size()-1; i >= 0; i--)
        if(coins[i] > y && coins[i] <= x){
            y = coins[i];
            break;
        }
    used_c.insert(y);
    withdraw(x-y,coins,curr_coin);
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<long int> coins(n);
        for(int i = 0; i < n; i++){
            cin>>coins[i];
        }
        long int max_w = coins[coins.size()-1]*(n-1);
        int max_c = -1;
        for(unsigned long int i = 3; i < max_w; i++){
            cout<<i<<endl;
            withdraw(i,coins, coins.size()-1);
            int tam = used_c.size();
            if(tam > max_c) max_c = tam;
            if(max_c == n){
                used_c.clear();
                break;
            }
            used_c.clear();
        }
        cout<<max_c<<endl;

    }

    return 0;
}