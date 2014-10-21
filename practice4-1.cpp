#include<stdio.h>
#include<stdlib.h>
#include <iostream>
const int n=7;
int fastestWay(int l[][n],int f[][n],int a[][n],int t[][n-1],int e[],int x[],int n)
{
    int i,j,ff,ll;
    f[1][1]=e[1]+a[1][1];
    f[2][1]=e[2]+a[2][1];
    
    for(j=2;j<n;j++)
    {
        if(f[1][j-1]+a[1][j]<=f[2][j-1]+t[2][j-1]+a[1][j])
        {
            f[1][j]=f[1][j-1]+a[1][j];
            l[1][j]=1;
        }
        else
        {
            f[1][j]=f[2][j-1]+t[2][j-1]+a[1][j];
            l[1][j]=2;
        }

        if(f[2][j-1]+a[2][j]<=f[1][j-1]+t[1][j-1]+a[2][j])
        {
            f[2][j]=f[2][j-1]+a[2][j];
            l[2][j]=2;
        }
        else
        {
            f[2][j]=f[1][j-1]+t[1][j-1]+a[2][j];
            l[2][j]=1;
        }
    }
    if(f[1][n-1]+x[1]<=f[2][n-1]+x[2])
    {
        ff=f[1][n-1]+x[1];
        l[1][1]=1;//利用l[1][1]保存出站的最后一个装配站
    }
    else
    {
        ff=f[2][n-1]+x[2];
        l[1][1]=2;
    }
    return (ff);
}

int main(void)
{
    int i,j,k;
    int a[3][7],t[3][6];//a[i][j]记录经过装配线i的装配站j所用的时间,t[i][j]记录由装配线i的装配站Si,j移动到另一条装配线所需要的时间
    int e[3]={0,2,4};
    int x[3]={0,3,2};
    int l[3][7],f[3][7];//l[i][j]用于记录通过装配站Si,j的最快路径中经过的前一站所在的装配线
    int b[2][6]={{7,9,3,4,8,4},{8,5,6,4,5,7}};
    int c[2][5]={{2,3,1,3,4},{2,1,2,2,1}};
    for(i=0;i<2;i++)
        for(j=0;j<6;j++)
            a[i+1][j+1]=b[i][j];
    for(i=0;i<2;i++)
        for(j=0;j<5;j++)
            t[i+1][j+1]=c[i][j];
    k=fastestWay(l,f,a,t,e,x,n);
    printf("汽车装配的最少时间为：%d\n",k);
    int cc[n+1];//用于将l[i][j]中的结果正向输出
    cc[n]=l[1][1];//将最后经过的装配站所在的装配线放入cc[n]
    for(i=6;i>=2;i--)
        cc[i]=l[cc[i+1]][i];
    printf("汽车装配经过的装配线和装配站情况如下：\n");
    for(i=2;i<=n;i++)
        printf("line %d , station %d \n",cc[i],i-1);     
        std::cin.get();
		return 0;   
}
