#include <stdio.h>
void printUp(int amp);
void printDown(int amp);
int main(){
	int n,amp,freq,i,j;
	scanf("%d",&n);
	while(n--){
		scanf("%d\n%d",&amp,&freq);
		for(j=0;j<freq;j++){
			printUp(amp);
			printDown(amp);
			if(j!=freq-1) printf("\n");
		}
		if(n) printf("\n");
	}
	return 0;
}
void printUp(int amp){
	int i,j;
	for(i=1;i<=amp;i++){
		for(j=0;j<i;j++) printf("%d",i);
			printf("\n");
	}
}
void printDown(int amp){
	int i,j;
	for(i=amp-1;i>0;i--){
		for(j=i;j>0;j--) printf("%d",i);
			printf("\n");
	}
}