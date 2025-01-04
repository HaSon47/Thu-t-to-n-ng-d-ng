#include<bits/stdc++.h>
#define N 1000001
using namespace std;
const int Q = 1e9 + 7;
int n, a[N];
long long res=0;

//Tính số inversion từ al,...,ar đồng thời sắp xếp tăng dần
void Call(int l, int r){
    if(l>=r) return;

    int mid = (l+r)/2;
    Call(l,mid); Call(mid+1,r);

    int tmp[r-l+1]; int cur=0;
    int i=l, j=mid+1;
    while(i<=mid && j<=r){
        if(a[i]>a[j]){
            tmp[cur++]=a[j++];
        }
        else{
            tmp[cur++]=a[i++];
            res += (j-1-mid);
        }
    }
    while(j<=r){
        tmp[cur++]=a[j++];
    }
    while(i<=mid){
        tmp[cur++]=a[i++];
        res += (r-mid);
    }
    for(int k=0;k<cur;k++){
        a[l+k]=tmp[k];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    Call(1,n);
    cout<<res%Q;
    return 0;
}
