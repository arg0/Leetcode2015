#include <iostream>
#include <vector>

using namespace std;


int solution(vector< vector<int> > &A) {
	int sumx=0;int sumy=0;
	vector<int> resx,resy;
	if(A.empty() || A[0].empty()) return 0;
	int n=A.size();int m=A[0].size();//n row . m cols
	int top=0;int bottom=n-1;
	int left=0;int right=m-1;
	int r=0;int c=0;
	while(1){
		int sizex=resx.size();int sizey=resy.size();
		while(c<=right && c>=left && r<=bottom && r>=top ){
			resx.push_back(A[r][c]);resy.push_back(A[r][c]);
			sumx+=A[r][c];sumy+=A[n-r-1][m-c-1];
			c++;
		}
		top+=1;r+=1;c-=1;bottom-=1;//l->r
		while(c<=right && c>=left && r<=bottom && r>=top ){
			resx.push_back(A[r][c]);resy.push_back(A[r][c]);
			sumx+=A[r][c];sumy+=A[n-r-1][m-c-1];
			r++;
		}
		right-=1;r-=1;c-=1;left+=1;//up->down
		while(c<=right && c>=left && r<=bottom && r>=top ){
			resx.push_back(A[r][c]);resy.push_back(A[r][c]);
			sumx+=A[r][c];sumy+=A[n-r-1][m-c-1];
			c--;	
		}
		top+=1;c+=1;r-=1;bottom-=1;//r->l
		while(c<=right && c>=left && r<=bottom && r>=top ){
			resx.push_back(A[r][c]);resy.push_back(A[r][c]);
			sumx+=A[r][c];sumy+=A[n-r-1][m-c-1];
		}
		right-=1;r+=1;c+=1;left+=1;//down->up
		if(sizex==resx.size()&&sizey==resy.size())break;
	}
	cout<<sumx<<" "<<sumy<<endl;
}

int main(void){
	vector< vector<int> > A={
								{5,3,8,9,4,1,3,-2},
								{4,6,0,3,6,4,2,1},
								{4,5,3,1,9,5,6,6},
								{3,7,5,3,2,8,9,4},
								{5,3,3,6,3,2,8,0},
								{5,7,5,3,3,-9,2,2},
								{0,4,3,2,5,7,5,4},
							};
	int k=solution(A);
	cout<<"end k= "<<k;
	
	cin.get();
	return 0;
}


