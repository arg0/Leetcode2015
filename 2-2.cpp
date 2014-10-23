#include <iostream>
#include <vector>

using namespace std;
int solution(vector< vector<int> > &A) {
	int sumx=0;int sumy=0;
	vector<int> resx,resy;
	if(A.empty()||A[0].empty()) return 0;
	int n=A.size();int m=A[0].size();//n row . m cols
	int top=0;int bottom=n-1;int left=0;int right=m-1;
	int r=0;int c=0;int size=n*m/2;
	while(1){
		while(c<=right && c>=left && r<=bottom && r>=top ){
			sumx+=A[r][c];sumy+=A[n-r-1][m-c-1];
			c++;size--;
		}top+=1;r+=1;c-=1;bottom-=1;//l->r
		while(c<=right && c>=left && r<=bottom && r>=top ){
			sumx+=A[r][c];sumy+=A[n-r-1][m-c-1];
			r++;size--;
		}right-=1;r-=1;c-=1;left+=1;//up->down
		while(c<=right && c>=left && r<=bottom && r>=top ){
			sumx+=A[r][c];sumy+=A[n-r-1][m-c-1];
			c--;size--;
		}top+=1;c+=1;r-=1;bottom-=1;//r->l
		while(c<=right && c>=left && r<=bottom && r>=top ){
			sumx+=A[r][c];sumy+=A[n-r-1][m-c-1];
			r--;size--;
		}right-=1;r+=1;c+=1;left+=1;//down->up
		if(size<0)break;
	}
	return resx;
	cout<<sumx<<" "<<sumy<<endl;
}

    while(1) {
      int size = result.size();
      while(c <= right && c >= left && r <= bottom && r >= top) {
        result.push_back(matrix[r][c++]);
      }
      top++;c--;r++;
      while(c <= right && c >= left && r <= bottom && r >= top) {
        result.push_back(matrix[r++][c]);
      }
      right--;r--;c--;
      while(c <= right && c >= left && r <= bottom && r >= top) {
        result.push_back(matrix[r][c--]);
      }
      bottom--;c++;r--;
      while(c <= right && c >= left && r <= bottom && r >= top) {
        result.push_back(matrix[r--][c]);
      }
      left++;r++;c++;
      if(size == result.size())break;
    }
    return result;
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


