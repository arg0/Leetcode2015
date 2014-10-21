#include <iostream>

using namespace std;
//const int MAX=10000000; 
void merge(int *data,int p,int q,int r){
	int n1,n2,i,j,k;
	int *left=NULL,*right=NULL;
	
	n1=q-p+1;
	n2=r-q;
	
	left=(int *)malloc(sizeof(int)*n1);
	right=(int *)malloc(sizeof(int)*n2);
	for(i=0;i<n1;i++){
		left[i]=data[p+i];
	}
	for(j=0;j<n2;j++){
		right[j]=data[q+1+j];
	}
	
	i=j=0;k=p;
	while(i<n1&&j<n2){
		data[k++]=(left[i]<=right[j]?left[i++]:right[j++]);
	}
	
	for(;i<n1;i++){
		data[k++]=left[i];
	}
	for(;j<n2;j++){
		data[k++]=right[j];
	}
}

void mergesort(int *data,int p,int r){
	int q;
	if(q<r){
		q=(int)((p+r)/2);
		mergesort(data,p,q);
		mergesort(data,q+1,r);
		merge(data,p,q,r);
	}
}

int main(void){
	int n=10;int a[10]={3,2,6,7,10,2,8,1,9,5};
	int *input=a;
	mergesort(input,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cin.get();
	
	return 0;
}
