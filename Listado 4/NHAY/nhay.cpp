#include <bits/stdc++.h>
using namespace std;

int main(){
    int len;
    string needle, haystack;
    while(cin>>len){
        cin>>needle>>haystack;
        int pos = 0, next;
        while((next = haystack.find(needle,pos)) != string::npos){
            cout<<next<<endl;
            pos = next + 1;
        }
        if(pos != 0) cout<<endl;
    }

    return 0;
}