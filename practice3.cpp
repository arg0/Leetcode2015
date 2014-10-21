#include <iostream>

using namespace std;
void BuildHeap(int a[],int size);
void Maxify(int a[],int i,int size);
void HeapSort(int a[],int length);
int Lefti(int i){
	return 2*i;
}
int Righti(int i){
	return 2*i+1;
}
void exchange(int a[],int i,int j){
	int tmp=a[i];
	a[i]=a[j];
	a[j]=tmp;
}
int a[10]={4,2,6,7,10,3,8,1,9,5};
int main(void){
	//int a[10]={4,2,6,7,10,3,8,1,9,5};
	
	int length=sizeof(a)/sizeof(int);
	HeapSort(a,length);
	for(int i=0;i<length;i++){
		cout<<a[i]<<" ";
	}
	
	cin.get();
	return 0;
}

void Maxify(int a[],int i,int size){
	int l=Lefti(i);
	int r=Righti(i);
	int largest;
	if(l<size&&a[l]>a[i]){
		largest=l;
	}else{
		largest=i;
	}
	if(r<size&&a[r]>a[largest]){
		largest=r;
	}
	if(largest!=i){
		exchange(a,i,largest);
		Maxify(a,largest,size);
	}	
}

void BuildHeap(int a[],int size){
	for(int i=(size-1)/2;i>0;i--){
		Maxify(a,i,size);
	}
}
//a[0] a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] a[9]

void HeapSort(int a[],int length){
	int size=length;
	BuildHeap(a,size);
	for(int i=length-1;i>1;i--){
		exchange(a,0,i);
		size--;
		Maxify(a,0,size);
	}
}
