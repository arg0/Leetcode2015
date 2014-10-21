#include <iostream>

using namespace std;
void BuildHeap(int a[],const int size);
void Maxify(int a[],int i,const int size);
void HeapSort(int a[],const int size);
int Lefti(int i){
	return 2*i+1;
}
int Righti(int i){
	return 2*i+2;
}
void exchange(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}
int largest=0;

int main(void){
	int a[10]={3,2,6,7,10,2,8,1,9,5};
	
	int size=sizeof(a)/sizeof(int);
	HeapSort(a,size);
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	
	cin.get();
	return 0;
}

void Maxify(int a[],int i,const int size){
	int l=Lefti(i);
	int r=Righti(i);
	if(l<=size&&a[l]>a[i]){
		largest=l;
	}else{
		largest=i;
	}
	if(r<=size&&a[r]>a[largest]){
		largest=r;
	}
	if(largest!=i){
		exchange(a[i],a[largest]);
		Maxify(a,largest,size);
	}	
}

void BuildHeap(int a[],const int size){
	for(int i=size/2;i>0;i--){
		Maxify(a,i,size);
	}
}

void HeapSort(int a[],const int size){
	BuildHeap(a,size);int avasize=size;
	for(int i=avasize;i>0;i--){
		exchange(a[1],a[i]);
		avasize--;
		Maxify(a,i,avasize);
	}
}
