#include<bits/stdc++.h>
using namespace std;
int dp[101][101][101];
void Solve(){
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            for(int z=1;z<=100;z++)
                dp[i][j][z]= i*j*z;
    int l,h,w,n;
    cin>>l>>w>>h;
    cin>>n;
    int x,y,z;
    for(int i=0;i<n;i++){
        cin>>x>>y>>z;
        dp[x][y][z]=0;
        dp[x][z][y]=0;
        dp[y][x][z]=0;
        dp[y][z][x]=0;
        dp[z][x][y]=0;
        dp[z][y][x]=0;
    }
    for(int i=1;i<=l;i++)
    for(int j=1;j<=w;j++)
    for(int z=1;z<=h;z++){
        for(int cut=1;cut<i;cut++){
            dp[i][j][z]= min(dp[i][j][z],dp[cut][j][z]+dp[i-cut][j][z]);
        }
        for(int cut=1;cut<j;cut++){
            dp[i][j][z]= min(dp[i][j][z],dp[i][cut][z]+dp[i][j-cut][z]);
        }
        for(int cut=1;cut<z;cut++){
            dp[i][j][z]= min(dp[i][j][z],dp[i][j][cut]+dp[i][j][z-cut]);
        }
    }
    cout<<dp[l][w][h]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}
