//C++
#include<iostream>
#define N 1000001
using namespace std;
int n;
int a[N];
bool B0[N]={}, B1[N]={};
long long S0[N]={}, S1[N]={};
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    if(a[0]%2 ==0){
        S0[0] = a[0]; B0[0] = true;
    } else{
        S1[0] = a[0]; B1[0] = true;
    }
    for(int i=1;i<n;i++){
        if(a[i]%2 == 0){
            if(B0[i-1]){if(S0[i-1]>0) S0[i]=S0[i-1]+a[i]; else S0[i] = a[i]; B0[i]=true;}
            else{ S0[i] = a[i]; B0[i] = true;}
            if(B1[i-1]){S1[i] = S1[i-1] + a[i]; B1[i] = true;}
        }else{
            if(B1[i-1]){S0[i] = S1[i-1] + a[i]; B0[i] = true;}
            if(B0[i-1]){
                if(S0[i-1]>0) S1[i] = S0[i-1] + a[i]; else S1[i] = a[i];
                B1[i] = true;
            }else{S1[i] = a[i]; B1[i] = true;}
        }
    }
    long long max_even = -1e4;
    for(int i=0;i<n;i++){
        if(B0[i] && max_even<S0[i]) max_even = S0[i];
    }
    cout<<max_even;
}

