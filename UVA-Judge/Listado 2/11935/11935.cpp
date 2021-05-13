#include <bits/stdc++.h>
using namespace std;

int get_n(string line){
    string aux = "";
    aux += line[line.size()-2];
    aux += line[line.size()-1];
    int n = stoi(aux);
    return n;
}

int main(){
    string line;
    while(getline(cin,line)){
        if(line == "0 Fuel consumption 0"){
            break;
        }
        int d_i = 0, d_f = 0, n = get_n(line), leak = 0;
        double fuel = 0.0, tank = 0.0;
        while(getline(cin,line)){
            istringstream ss(line);
            string action;
            ss>>d_f;
            ss>>action;
            d_f = d_f - d_i;
            d_i = d_f + d_i;
            if(leak > 0){
                fuel += d_f*leak;
            }

            fuel += (n*d_f)/100.0;
            tank = max(fuel,tank);
            if(action == "Fuel"){
                n = get_n(line);
            }
            if(action == "Goal"){
                break;
            }
            else if(action == "Gas"){
                d_f = 0;
                fuel = 0;
            }
            else if(action == "Leak"){
                leak++;
            }
            else if(action[0] == 'M'){
                leak = 0;
            }
        }
        printf("%.3f\n",tank);
    }
    return 0;
}