#include <bits/stdc++.h>
using namespace std;



int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> A(n);
        for(int i = 0; i < n; i++){
            cin>>A[i];
        }
        int c = 0;
        for(int i = A.size()-1; i >= 1; i--){
            for(int j = i-1; j >= 0; j--){
                if(A[j] <= A[i]){
                    c++;
                }
            }
        }
        cout<<c<<endl;
    }    
    return 0;
}