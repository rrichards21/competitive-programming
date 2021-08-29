#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long int a=0,b=1,c=1,d=0,num=1,den=1;
    cin>>N;
    string line;
    char path;
    getline(cin,line);
    for(int i = 0; i < N; i++){
        getline(cin,line);
        stringstream ss(line);
        while(ss>>path){
            if(path == 'R'){
                a = num; b = den;
            }
            else{
                c = num; d = den;
            }
            num = a + c;
            den = b + d;

        }
        cout<<num<<"/"<<den<<endl;
        a=0;b=1;c=1;d=0;num=1;den=1;

    }

    return 0;
}