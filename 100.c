#include <stdio.h>
int max_cycle(int i,int j);
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		printf("%d %d %d\n",a,b,max_cycle(a,b));
	}
	return 0;
}
int max_cycle(int i,int j){
	int cycle=1,max_cycle=0;
	int num=j;
	while(num!=i){
		if(j==1){
			j=num;
			cycle=1;
		}
		if(j%2==1) j=(3*j)+1;
		else j=j/2;
		if(cycle==1) num=num-1;
		cycle++;
		if(cycle>=max_cycle) max_cycle=cycle;
	}
	return max_cycle;
}