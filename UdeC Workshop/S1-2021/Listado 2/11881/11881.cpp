#include <bits/stdc++.h>
using namespace std;

vector<int> cf;

double fun(double IRR){
    double NPV = cf[0];
    for(int i = 1; i < cf.size(); i++){
        NPV += cf[i]/pow((1+IRR),i);
    }
    return NPV;
}

double bs(){
    double L = -1, R = pow(10,6),m;
    int iter = 0;
    while(true){
        m = (L + R) / 2;
        if(iter == 100) break;
        if(fun(m) > 0){
            L = m;
        }
        else if(fun(m) < 0){
            R = m;
        }
        iter++;
    }
    return m;
}

int main(){
    int T;
    cin>>T;
    while(T != 0){
        cf.resize(T+1);
        for(int i = 0; i <= T; i++){
            scanf("%d",&cf[i]);
        }
        printf("%.2f\n",bs());
        cin>>T;
    }
    return 0;
}