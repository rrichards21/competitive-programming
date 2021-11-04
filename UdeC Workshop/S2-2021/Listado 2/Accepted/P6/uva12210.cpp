/*
Autor: Rodrigo Richards
A Match Making Problem - 12210
rrichards - 958045
Código realizado por mí
*/
#include <bits/stdc++.h>
using namespace std;

bool comp(const int a, const int b){
    return a > b;
}

int main(){
    int b,s,c=0;
    while(cin>>b>>s,b!=0,s!=0){
        vector<int> bachelors(b);
        list<int> spinsters;
        for(int i = 0; i < b; i++){
            cin>>bachelors[i];
        }
        int sp;
        for(int i = 0; i < s; i++){
            cin>>sp;
            spinsters.push_back(sp);
        }
        sort(bachelors.begin(), bachelors.end(), comp);
        spinsters.sort(comp);
        int marr = 0;
        int min = INT_MAX;
        for(int i = 0; i < b; i++){
            auto it = spinsters.begin();
            if(it == spinsters.end()){
                while(i < b){
                    if(bachelors[i] < min) min = bachelors[i];
                    i++;
                }
                break;
            }
            int diff = abs((*it) - bachelors[i]);
            auto prev = it;
            while(it != spinsters.end()){
                if(abs((*it) - bachelors[i]) > diff){
                    spinsters.erase(prev);
                    marr++;
                    break;
                }
                diff = abs((*it) - bachelors[i]);
                prev = it;
                it++;
            }
            if(it == spinsters.end()){
                spinsters.erase(prev);
                marr++;
            }
        }
        cout<<"Case "<<++c<<": ";
        if(marr != b){
            cout<<b-marr<<" "<<min<<endl;
        }
        else{
            cout<<"0"<<endl;
        }

    }

    return 0;
}