#include <bits/stdc++.h>
using namespace std;
void Tokenize(const string& str, const string& delimiters,vector<int>& p);
void TokenizeFl(const string& str, const string& delimiters,string* arr,std::vector<int> v);
int main(){
	ios::sync_with_stdio(false);
	vector<int> p;
	string linea;
	int N;
	double fl;
	cin>>N;
	for (int i = 0; i < N; ++i){
		getline(cin,linea);
		while(linea.length()==0){
			getline(cin,linea);
		}
		Tokenize(linea," ",p);
		getline(cin,linea);
		string arr[p.size()];
		TokenizeFl(linea," ",arr,p);
		for (int i = 0; i < p.size(); ++i)
		{
			cout<<arr[i]<<"\n";
		}
		if(i!=N-1) cout<<"\n";
		p.clear();
	}
	return 0;
}
void Tokenize(const string& str, const string& delimiters,vector<int>& p){
	vector<string> tokens;
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos     = str.find_first_of(delimiters, lastPos);
	while (string::npos != pos || string::npos != lastPos){
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}
	for(vector<string>::iterator i = tokens.begin(); i != tokens.end(); ++i){
		stringstream ss(*i);
		int num;
		ss >> num;
		p.push_back(num);
    }
}
void TokenizeFl(const string& str, const string& delimiters,string* arr,std::vector<int> v){
	vector<string> tokens;
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos     = str.find_first_of(delimiters, lastPos);
	int i=0;
	while (string::npos != pos || string::npos != lastPos){
		arr[v[i]-1]=str.substr(lastPos, pos - lastPos);
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
		i++;
	}
}