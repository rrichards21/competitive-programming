#include <bits/stdc++.h>
using namespace std;
int GCD(int a,int b);
bool factor1(int a,int b);
void pii(int f,int s);
int main(){
	int N;
	vector<int> nums;
	cin>>N;
	while(N!=0){
		int cont=0,pairs=0;;
		for(int i=0;i<N;i++){
			int n;
			cin>>n;
			nums.push_back(n);
		}
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				if(GCD(nums[i],nums[j])==1) cont++;
				pairs++;
			}
		}
		pii(cont,pairs);
		cin>>N;
		nums.clear();
	}
	return 0;
}
bool factor1(int a,int b){
	int cont=0;
	for(int i=1;i<=a;i++){
		if(a%i==0 && b%i==0) cont++;
	}
	if(cont>1) return false;
	return true;
}
void pii(int f,int s){
	if(f!=0) printf("%.6f\n",sqrt(6*s*1.0/f));			//por qué 1.0 cambia el resultado?
	else printf("No estimate for this data set.\n");
}
int GCD(int a,int b){		//Euclydian algorithm Greatest Common Divisor
	int div;
	while(a%b!=0){
		div=a;
		a=b;
		b=div%b;
	}
	return b;
}