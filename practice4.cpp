#include <iostream>
using namespace std;
const int n=7;
int fway(int l[][n],int f[][n],int a[][n],int t[][n-1],int e[],int x[],int n){
	int i,j,ff,ll;
	f[1][1]=e[1]+a[1][1];
	f[2][1]=e[2]+a[2][1];
	
	for(j=2;j<n;j++){
		if(f[1][j-1]+a[1][j]<=f[2][j-1]+a[1][j]+t[2][j-1]){
			f[1][j]=f[1][j-1]+a[1][j];
			l[1][j]=1;
		}else{
			f[1][j]=f[2][j-1]+a[1][j]+t[2][j-1];
			l[1][j]=2;
		}
		if(f[2][j-1]+a[2][j]<=f[1][j-1]+a[2][j]+t[1][j-1]){
			f[2][j]=f[2][j-1]+a[2][j];
			l[2][j]=1;
		}else{
			f[2][j]=f[1][j-1]+a[2][j]+t[1][j-1];
			l[2][j]=2;
		}
	}
	if(f[1][n-1]+x[1]<=f[2][n-1]+x[1]){
		ff=f[1][n-1]+x[1];
		l[1][1]=1;
	}else{
		ff=f[2][n-1]+x[2];
		l[1][1]=2;
	}
	return ff;
}

int main(void){
	int i,j,k;
	int a[3][7],t[3][6];
    int e[3]={0,2,4};
    int x[3]={0,3,2};
    int l[3][7],f[3][7];
    int b[2][6]={{7,9,3,4,8,4},{8,5,6,4,5,7}};
    int c[2][5]={{2,3,1,3,4},{2,1,2,2,1}};
	for(i=0;i<2;i++)
       for(j=0;j<6;j++)
           a[i+1][j+1]=b[i][j];
    for(i=0;i<2;i++)
        for(j=0;j<5;j++)
            t[i+1][j+1]=c[i][j];
    k=fway(l,f,a,t,e,x,n);
    cout<<"Min-Time:"<<k<<endl;
    int cc[n+1];
    cc[n]=l[1][1];
    cc[0]=0;
    for(i=6;i>=2;i--)
        cc[i]=l[cc[i+1]][i];
    cout<<"Steps:"<<endl;
    for(i=2;i<=n;i++)
    	cout<<" Station: "<<i-1<<" line: "<<cc[i]<<endl;     
	cin.get();
	return 0;
} 
