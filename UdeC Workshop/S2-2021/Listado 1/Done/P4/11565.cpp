#include <bits/stdc++.h>
using namespace std;

int f1(int x, int y, int z){
    return x + y + z;
}

int f2(int x, int y, int z){
    return x*y*z;
}

int f3(int x, int y, int z){
    return (x*x) + (y*y) + (z*z);
}

bool test(int a, int b, int c){
    for(int x = -100; x <= 100; x++){
        for(int y = -100; y <= 100; y++){
            if(x == y) continue;
            for(int z = -100; z <= 100; z++){
                if(x == z || y == z) continue;
                if(f1(x,y,z) == a && f2(x,y,z) == b && f3(x,y,z) == c){
                    cout<<x<<" "<<y<<" "<<z<<endl;
                    return true;
                } 
            }
        }
    }
    return false;
}

int main(){
    int n,a,b,c;
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        bool solved = test(a,b,c);
        if(!solved) cout<<"No solution.\n";
    }
    return 0;
}