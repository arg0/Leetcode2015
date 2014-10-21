#include <iostream>

using namespace std;
void InsertionSort(int a[],int size);

int main(){
	int a[6]={5,2,4,6,1,3};
	int size=sizeof(a)/sizeof(int);
	InsertionSort(a,size);
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cin.get();
	return 0;
}

void InsertionSort(int a[],int size){
	int key=0;
	for(int j=1;j<size;j++){
		key=a[j];
		int i=j-1;
		while(i>=0&&a[i]>key){
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
}


