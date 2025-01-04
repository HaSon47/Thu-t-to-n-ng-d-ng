//C++
#include<iostream>
#include<algorithm>
#define N 100001
using namespace std;
int n,T,C;
int a[N];
void test_case(int *a){
    sort(a,a+n);
    int low = (a[n-1]-a[0])/(C-1);
    while(true){
        int num=1;
        int cur = 0;
        int i = 1;
        while(i<n){
            if(a[i] >= a[cur]+low){
                cur = i;
                num++;
                if(num==C){cout<<low<<endl; return;}
            }else i++;
        }
        low--;
    }
}
int main()
{
    cin>>T;
    while(T>0){
        cin>>n>>C;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        test_case(a);
        T--;
    }
    return 0;
}

