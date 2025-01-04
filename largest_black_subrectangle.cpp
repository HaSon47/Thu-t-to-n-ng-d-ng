#include<bits/stdc++.h>
#define N 1001
int n,m, Max=0;
int a[N][N];
using namespace std;
int Count_max_k(int k){
    int h[N]={};
    // count h[j]
    for(int j=1;j<=m;j++){
        if(a[k][j]==1){
            int tmp = k;
            while(tmp>0 && a[tmp][j]==1)
                {tmp--; h[j]++;}
        }
    }
    // count hcn max with range k
    int l,r, tmp; int Max = 0; h[0]=-1; h[m+1]=-1;
    for(int i=1;i<=m;i++){
        l=i-1; r=i+1;
        while(l>0 && h[l]>=h[i]) l--;
        while(r<=m && h[r]>=h[i]) r++;
        tmp = (r-l-1)*h[i];
        if(tmp>Max) Max=tmp;
    }
    return Max;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>a[i][j];

    // Tinh Max
    int Max_k;
    for(int k=1;k<=n;k++){
        Max_k = Count_max_k(k);
        if(Max_k> Max) Max = Max_k;
    }
    cout<<Max;
    return 0;
}
