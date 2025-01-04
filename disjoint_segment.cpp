#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin>>n;
    int **a;
    a = new int*[n];
    for(int i=0;i<n;i++){
        a[i]= new int[2];
    }
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];

    sort(a, a+n, [](int* r1, int* r2){
         return r1[1]<r2[1];
         });

    int cur = a[0][1];
    int num=1;
    for(int i=1;i<n;i++){
        if(a[i][0] > cur){
            cur = a[i][1];
            num++;
        }
    }
    cout<<num;
    return 0;
}
