/*
Autor: Rodrigo Richards
Coin Collector - 11264
rrichards - 958045
Código realizado por mí
*/

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
        int max_c = 1;
        //cambiar vector por int acumulador
        vector<int> acc(n,0);
        acc[0] = coins[0];

        for(int i = 1; i < coins.size()-1; i++){
            if(coins[i] + acc[i-1] < coins[i+1]){
                acc[i] = coins[i] + acc[i-1];
                max_c++;
            }
            else{
                acc[i] = acc[i-1];
            }
        }
        max_c++;
        cout<<max_c<<endl;

    }

    return 0;
}


//Idea
/*
Ir sumando desde la primera moneda el valor más cercano posible que no sobrepase el valor de la siguiente moneda


*/