#include <bits/stdc++.h>
using namespace std;

double fun(int p, int q, int r, int s, int t, int u ,double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u;
}

double bs(int p, int q, int r, int s, int t, int u){
    double L = 0, R = 1;
    double m;
    int iter = 0;
    while(true){
        m = (L+R)/2;
        if(iter == 500) break;
        if(fun(p,q,r,s,t,u,m) > 0){
            L = m;
        }
        else if(fun(p,q,r,s,t,u,m) < 0){
            R = m;
        }
        iter++;
    }
    return m;
}

int main(){
    int p,q,r,s,t,u;
    while(cin>>p>>q>>r>>s>>t>>u){
        if(fun(p,q,r,s,t,u,0)*fun(p,q,r,s,t,u,1) > 0){
            printf("No solution\n");
        }
        else{
            printf("%.4f\n",bs(p,q,r,s,t,u));
        }
    }
    return 0;
}