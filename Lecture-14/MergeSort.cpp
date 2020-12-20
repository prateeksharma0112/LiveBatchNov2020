// MergeSort
#include <iostream>
using namespace std;

void merge(int *a,int *b,int *c,int s,int e){
	int mid = (s+e)/2;

	int i = mid;
	int j = e;
	int k = e;

	while(i>=s && j>=mid+1){
		if(b[i]>c[j]){
			a[k--]=b[i--];
		}
		else{
			a[k--]=c[j--];
		}
	}

	while(i>=s){
		a[k--] = b[i--];
	}
	while(j>=mid+1){
		a[k--] = c[j--];
	}
}

void MergeSort(int *a,int s,int e){
	// base case
	if(s>=e){
		return;
	}

	// recursive case
	// 1. Divide
	int b[100],c[100];
	int mid = (s+e)/2;
	for(int i = s ; i<= mid ; i++){
		b[i]=a[i];
	}
	for(int i = mid+1; i<=e ; i++){
		c[i] = a[i];
	}

	// 2. Sort
	MergeSort(b,s,mid);
	MergeSort(c,mid+1,e);
	
	// 3. Merge
	merge(a,b,c,s,e);
}





int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int a[]={4,5,3,2,6,7,0,8,9,1,-2,-1};
	int n = sizeof(a)/sizeof(int);

	for(int i = 0 ; i < n ; i++){
		cout<<a[i]<<' ';
	}cout<<endl;

	MergeSort(a,0,n-1);

	for(int i = 0 ; i < n ; i++){
		cout<<a[i]<<' ';
	}cout<<endl;

	
	return 0;
}