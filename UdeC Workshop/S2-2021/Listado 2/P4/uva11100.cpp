#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n,n!=0){
        vector<int> bags(n);
        vector<bool> used(n,false);
        for(int i = 0; i < n; i++){
            cin>>bags[i];
        }
        sort(bags.begin(),bags.end());
        vector<vector<int> > sol;
        int c = 0;
        vector<int> aux;
        sol.push_back(aux);
        sol[0].push_back(bags[0]);
        for(int i = 1; i < bags.size(); i++){
            while(c < sol.size() && bags[i] == sol[c][sol[c].size()-1]){
                c++;
            }
            if(c == sol.size()){
                sol.push_back(aux);
                sol[sol.size()-1].push_back(bags[i]);

            }
            else{
                // while(c < sol.size() && bags[i] == sol[c][sol[c].size()-1] ) c++;
                sol[c++].push_back(bags[i]);
            }
            if(c > sol.size()-1) c = 0;
        }
        cout<<sol.size()<<endl;
        for(int i = 0; i < sol.size(); i++){
            for(int j = 0; j < sol[i].size(); j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}