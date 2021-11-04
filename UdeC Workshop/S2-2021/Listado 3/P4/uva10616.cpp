#include <bits/stdc++.h>
using namespace std;

int sol;

void groupSum(int sum, int curr, int D, int M, vector<int>& nums){
    if(M == 0){
        if(sum%D == 0){
            sol++;
            return;
        }
        return;
    }
    for(int i = curr; i < nums.size(); i++){
        groupSum(sum + nums[i], i + 1, D, M - 1, nums);
    }
}

int main(){
    int n, q, c = 1;
    while(cin>>n>>q,n!=0){
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        int D, M;
        cout<<"SET "<<c++<<":"<<endl;
        for(int i=1;i<=q;i++){
            cin>>D>>M;
            sol = 0;
            groupSum(0, 0, D, M, nums);
            cout<<"QUERY "<<i<<": "<<sol<<endl;
        }

    }
    return 0;
}