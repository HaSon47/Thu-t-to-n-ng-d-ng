#include<bits/stdc++.h>
#define N 5001
using namespace std;
int a[N];
int n;
int P=0;

// Tính tổng số cặp a_j + a_k = S từ l đến r
// Mảng a tăng dần
int Tinh(int l, int r, int S){
    int j = l, k=r, d=0, tmp;
    while(j<k){
        tmp = a[j]+a[k];
        if(tmp==S){
            j++; k--; d++;
        }else if(tmp<S) j++;
        else k--;
    }
    return d;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    //sắp xếp mảng a tăng dần
    sort(a+1,a+n+1);

    for(int i=n;i>=3;i--){
        P += Tinh(1,i-1,a[i]);
    }
    cout<<P;
    return 0;
}

