#include <bits/stdc++.h>
using namespace std;
void tokenize(const string& str,multimap<string,string>& m);
int main(){
	multimap<string,string> lovers;
	string linea;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		getline(cin,linea);
		if(linea.length()==0) getline(cin,linea);
		tokenize(linea,lovers);
	}
	int sum =1;
	for (std::multimap<string,string>::iterator i = lovers.begin(); i != lovers.end(); ++i){
		if(i->first!=next(i,1)->first){
			cout<<i->first<<" "<<sum<<endl;
			sum=0;
		}
		sum++;
	}
	return 0;
}
void tokenize(const string& str,multimap<string,string>& m){
	string::size_type lastPos = str.find_first_not_of(" ",0);
	string::size_type pos = str.find_first_of(" ",lastPos);
	string country;
	country = str.substr(lastPos,pos - lastPos);
	pos = str.find_first_not_of(" ",pos - lastPos);
	string lov = str.substr(pos,str.length());
	m.insert(std::pair<string,string>(country,lov));	
}