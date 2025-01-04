#include<bits/stdc++.h>
#define N 10001
using namespace std;
int n,m;
int X[N], Y[N];
int M[N][N]={};
int Max_sub=0;
int LSC(int i,int j){
    if(i==0 || j==0) return 0;
    if (M[i][j]!= -1) return M[i][j];

    int lsc = LSC(i-1,j);
    lsc = max(lsc, LSC(i,j-1));
    if(X[i]==Y[j]) lsc = max(lsc, 1+LSC(i-1,j-1));

    M[i][j]=lsc;
    return lsc;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>X[i];
    for(int i=1;i<=m;i++) cin>>Y[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            M[i][j]=-1;
    cout<<LSC(n,m);
    return 0;
}
