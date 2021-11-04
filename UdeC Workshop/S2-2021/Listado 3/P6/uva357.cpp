#include <bits/stdc++.h>
using namespace std;

map<int, int> dp;
//int ans;

int coinCombinations(int sum){
    cout<<sum<<endl;
    if(sum == 0){ return 1;}
    if(sum < 0) return 0;
    if(dp.count(sum)){ return dp[sum];}
    int ans = 0;
    int coins[] = {1,5,10,25,50};
    for(int i = 0; i < 5; i++){
        ans += coinCombinations(sum-coins[i]);
    }
    dp[sum] = ans;
    return dp[sum];
}

int main(){
    int cents;
    while(cin>>cents){
        dp = {};
        //ans = 0;
        cout<<coinCombinations(cents);
        // cout<<ans<<endl;    
    }
    return 0;
}