#include <iostream>
#include <vector>

using namespace std;
bool canJump(int A[],int n);

int main(){
	int A[5]={2,3,1,0,4};
	int B[0];
	cout<<canJump(A,5);
	cout<<canJump(B,0);
	return 0;
}

bool canJump(int A[],int n){
	int steps=0;int stepsmax=0;
	int sublength=n;
	int i=0;
	vector<int> B;
	
	for(steps=0;steps<sublength;steps++){
		if(steps==A[sublength-steps]){
			B.push_back(steps);		
		}
//		stepsmax=B.pop_back();
		sublength=sublength-stepsmax;
	}
	if(B.size()==0){
		return true;
	}
	
}
