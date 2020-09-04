#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    fflush(stdin);
    string line;
    stack<char> s;
    for(int i = 0; i < n; i++){
        getline(cin,line);
        fflush(stdin);
        if(line.size() == 0){
            continue;
        }
        if(line[0] == ')' || line[0] == ']'){
            printf("No\n");
            continue;
        }
        for(int j = 0; j < line.size(); j++){
            if(line[j] == '(' || line[j] == '['){
                s.push(line[j]);
            }
            else{
                try{
                    s.pop();
                }
                catch(int e){
                    printf("No\n");
                    continue;
                }
            }
        }
        if(!s.empty()){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
    return 0;
}