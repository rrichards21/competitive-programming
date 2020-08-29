#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <sstream>
using namespace std;
double polynomial(vector<int> coef,int n);
int str2int(const string &str);
string stringcpy(const string &str,int j,int k);
int main(){
	int i=0,j=0,poly;
	int n,suma,k=0;
	string linea,num;
	vector<int> coefs,x;
	while(getline(cin,linea)){
		k=0;
		if(j%2==0){
			for(int i=0;i<=linea.length();i++){
				if(linea[i]==' ' || i==linea.length()){
					coefs.push_back(str2int(stringcpy(linea,i,k)));
					k=i;
				}
			}
		}
		else{
			for(int i=0;i<=linea.length();i++){
				if(linea[i]==' ' || i==linea.length()){
					x.push_back(str2int(stringcpy(linea,i,k)));
					k=i;
				}
			}
			for(int k=0;k<x.size();k++){
				cout<<llround(polynomial(coefs,x[k]));
				if(k!=x.size()-1) cout<<" ";
			}
			coefs.clear();
			x.clear();
			cout<<endl;
		}
		j++;
	}
	return 0;
}

int str2int(const string &str) {
  stringstream ss(str);
  int num;
  ss >> num;
  return num;
}

string stringcpy(const string &str,int j,int k){
	string num=str.substr(k,j);
	return num;
}
double polynomial(vector<int> c,int v){
	double sum=0;
	for(int i=0;i<c.size();i++){
		sum+=c[i]*pow(v,c.size()-1-i);
	}
	return sum;
}