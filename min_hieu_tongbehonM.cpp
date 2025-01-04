#include<bits/stdc++.h>
using namespace std;
int n,M;
int a[21];
int S[21][100001]={};
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>M;

    for(int j=0;j<=M;j++) S[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=M;j++){
            if (j >= a[i]) {
                // Có thể chọn a[i]
                S[i][j] = max(S[i-1][j], S[i-1][j-a[i]] + a[i]);
            } else {
                // Không thể chọn a[i]
                S[i][j] = S[i-1][j];
            }
        }
    }
    cout<<M-S[n][M];
    return 0;

}


