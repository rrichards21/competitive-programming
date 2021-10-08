#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<vector<int> > M;
        vector<int> cols(n);
        for(int i = 0; i < n; i++){
            cols[i] = i;
            vector<int> row(n);
            for(int j = 0; j < n; j++){
                cin>>row[j];
            }
            M.push_back(row);
        }

        int best_choice = 999999;
        do{
            int curr_candies = 0;
            for(int i = 0; i < cols.size(); i++){
                curr_candies += M[i][cols[i]];
            }
            if(curr_candies < best_choice){
                best_choice = curr_candies;
            }
        }while(next_permutation(cols.begin(), cols.end()));
        cout<<best_choice<<endl;
    }

    return 0;
}