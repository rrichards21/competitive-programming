#include <bits/stdc++.h>
using namespace std;

int permutation(int score, int combinations = 0){
    if(score < 0){
        return 0;
    }
    if(score == 0){
        return ++combinations;
    }
    for(int i = 1; i <= 20; i++){
        cout<<score-i<<endl;
        return permutation(score-i, combinations);
    }
}

int main(){
    int n;
    while(cin>>n, n > 0){
        cout<<permutation(n)<<endl;
    }
    return 0;
}