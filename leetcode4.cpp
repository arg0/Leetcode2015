#include <iostream>

using namespace std;
int singleNumber(int A[],int n);

int main(){
	int A[9]={2,5,1,7,2,7,1,8,8};
	int r=singleNumber(A,9);
	cout<<r;
	return 0;
}
int singleNumber(int A[],int n){
	if(!n) return 0;
	int res=A[0];
	for(int i=1;i<n;i++){
		res=res^A[i];
	}
	return res;
}
