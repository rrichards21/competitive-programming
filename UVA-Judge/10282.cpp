#include <bits/stdc++.h>
using namespace std;
void tokenize(const string& str,map<string,string>& dict){
	string::size_type lastPos = str.find_first_not_of(" ",0);
	string::size_type pos = str.find_first_of(" ",lastPos);
	string code;
    vector<string> aux;
	while(string::npos != pos || string::npos != lastPos){
		code = str.substr(lastPos,pos - lastPos);
        aux.push_back(code);
		lastPos = str.find_first_not_of(" ",pos);
		pos = str.find_first_of(" ",lastPos);
	}
	dict.insert(make_pair(aux[1],aux[0]));
}

int main(){
    map<string,string> dict;
    string word,code;
    string linea;
    getline(cin,linea);
    while(linea != ""){
        tokenize(linea,dict);
        getline(cin,linea);
    }
    while(getline(cin,linea)){
      auto it = dict.find(linea);
      if(it != dict.end()){
        cout<<(*it).second<<endl;
      }
      else{
        cout<<"eh"<<endl;
      }
    }
}