//C++
#include<bits/stdc++.h>
#define N 1001
using namespace std;
struct toado{
    int x;
    int y;
    long long c;
};
int n;
long long Max=0;
long long S[N]={};
int main()
{
    cin>>n; toado T[n];
    for(int i=0;i<n;i++) {cin>>T[i].x>>T[i].y>>T[i].c;}

    sort(T, T+n, [](toado &x1, toado &x2){
         if(x1.x != x2.x) return x1.x<x2.x;
         return x1.y<x2.y;
         } );

    // Tinh S[i]: luong vang max neu diem cuoi la T[i]
    S[0] = T[0].c;
    for(int i=1;i<n;i++){
        S[i] = T[i].c;
        for(int j=i-1;j>=0;j--){
            if(T[j].y<=T[i].y) S[i] = max(S[i], S[j]+T[i].c);
        }
        Max = max(Max,S[i]);
    }
    cout<<Max;
    return 0;
}

