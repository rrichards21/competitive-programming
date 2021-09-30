#include <iostream>
using namespace std;

long long int cnt;
void merge(long arr[], long l, long m, long r)
{
	long n1 = m - l + 1;
	long n2 = r - m;

	long L[n1], R[n2];
	for (long i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (long j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	long i = 0;
	long j = 0;
	long k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			cnt += n1-i;
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(long arr[],long l,long r){
	if(l>=r){
		return;
	}
	long m =l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}

int main()
{
    long n;
    while(cin>>n){
        long *arr = (long*)malloc(n*sizeof(long));
        for(long i = 0; i < n; i++){
            scanf("%ld",&arr[i]);
        }
        cnt = 0;
        mergeSort(arr, 0, n-1);
        cout<<cnt<<endl;

    }
	return 0;
}