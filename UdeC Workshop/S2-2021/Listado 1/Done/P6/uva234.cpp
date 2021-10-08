#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pd;

int main()
{
    int p,v,a,ds=1;
    vector<int> sol;
    while(cin>>p, p!=0){
        vector<int> programs(p);
        for(int i = 0; i < p; i++){
            cin >> programs[i];
        }
        cin>>a;
        priority_queue<pd, vector<pd>, greater<pd> > pq;
        for(int i = 0; i < a; i++){
            int imp,t;
            cin>>imp>>t;
            pq.push(make_pair(imp,t));
        }
        vector<pd > alg_pnt;
        while(!pq.empty()){
            alg_pnt.push_back(pq.top());
            pq.pop();
        }
        int best_diff = INT_MAX;
        do {
            vector<int> arranged_p(p+1,0);
            arranged_p[1] = programs[0];
            int curr_sum = arranged_p[1];
            for(int i = 2; i <= p; i++){
                curr_sum += programs[i-1];
                arranged_p[i] = curr_sum;
            }
            int actual_diff = 0;
            vector<bool> used(p+1,false);
            for(int i = 0; i < alg_pnt.size(); i++){
                int min_diff = INT_MAX;
                for(int j = 0; j < arranged_p.size(); j++){
                    int curr_diff = abs(alg_pnt[i].second - arranged_p[j]);
                    if(curr_diff < min_diff){
                        min_diff = curr_diff;
                        used[j] = true;
                    }
                }
                actual_diff += min_diff;
            }
            if(actual_diff < best_diff){
                best_diff = actual_diff;
                sol = programs;
            }
        } while(next_permutation(programs.begin(),programs.end()));

        cout<<"Data set "<<ds++<<endl;
        cout<<"Order: ";
        for(int i = 0; i < programs.size(); i++){
            cout<<sol[i]<<" ";
        }
        cout<<endl;
        cout<<"Error: "<<best_diff<<endl;

    }
}