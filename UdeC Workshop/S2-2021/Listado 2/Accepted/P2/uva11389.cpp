/*
Autor: Rodrigo Richards
The Bus Driver Problem - 11389
rrichards - 958045
Código realizado por mí
*/
#include <bits/stdc++.h>
using namespace std;
bool comp(const int& a, const int& b){
    return a > b;
}
int main(){
    int n,d,r;
    while(cin>>n>>d>>r,n != 0){
        vector<int> morn_routes(n);
        vector<int> even_routes(n);
        for(int i = 0; i < n; i++){
            cin>>morn_routes[i];
        }
        for(int i = 0; i < n; i++){
            cin>>even_routes[i];
        }
        sort(morn_routes.begin(), morn_routes.end());
        sort(even_routes.begin(), even_routes.end(), comp);

        int overtime = 0;
        for(int i = 0; i < n; i++){
            int hrs = morn_routes[i] + even_routes[i];
            if(hrs > d){
                overtime += (hrs-d) * r;
            }
        }
        cout<<overtime<<endl;

    }
    return 0;
}