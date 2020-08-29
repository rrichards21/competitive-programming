#include <bits/stdc++.h>
using namespace std;
void tokenize(const string& str,vector<int>& salary);
int main(){
	std::vector<int> salary;
	string linea;
	int N;
	cin>>N;
	for (int i = 0; i < N; ++i){
		getline(cin,linea);
		if(linea.length()==0) getline(cin,linea);
		tokenize(linea,salary);
		int max=0,min=10000,med;
		for (std::vector<int>::iterator i = salary.begin(); i != salary.end(); ++i){
			if(*i>=max) max=*i;
			if(*i<=min) min=*i;
			med=*i;
		}
		for (std::vector<int>::iterator i = salary.begin(); i != salary.end(); ++i)
		{
			if(*i!=max && *i!=min) med=*i;
		}
		cout<<"Case "<<i+1<<": "<<med<<endl;
		salary.clear();
	}
}
void tokenize(const string& str,vector<int>& salary){
	string::size_type lastPos = str.find_first_not_of(" ",0);
	string::size_type pos = str.find_first_of(" ",lastPos);
	string num;
	while(string::npos != pos || string::npos != lastPos){
		num = str.substr(lastPos,pos - lastPos);
		stringstream ss(num);
		int val;
		ss >> val;
		salary.push_back(val);
		lastPos = str.find_first_not_of(" ",pos);
		pos = str.find_first_of(" ",lastPos);
	}
}