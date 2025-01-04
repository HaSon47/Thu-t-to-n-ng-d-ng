#include<bits/stdc++.h>
#define N 100
using namespace std;
int n,k,D;
int c[N][N];
int X[N], Y[N];
int cmin=10000, f_best=10000,f=0, load=0;
bool v[N]={};

bool Check(int i, int t){
    if(v[i]) return false;
    if(i<=n) return load<k;
    return (v[i-n] && (f+c[X[t-1]][i]-Y[i-n])>=D);
}

void Result(int i){
    if(f+c[i][0]<f_best) f_best = f+c[i][0];
}
void Try(int t){
    for(int i=1;i<=2*n;i++){
        if(Check(i,t)){
            X[t]=i; f+= c[X[t-1]][i]; v[i]=true;
            if(i<=n){
                load++;
                Y[i]=f;
            }
            else{
                load--;
            }
            if(t==2*n) Result(i);
            else if (f+cmin*(2*n-t)<f_best){
                Try(t+1);
            }
            f-=c[X[t-1]][i]; v[i]=false;
            i>n ? load++ : load--;
        }
    }
}
int main()
{
    cin>>n>>k>>D;
    for(int i=0;i<=2*n;i++)
    for(int j=0;j<=2*n;j++){
        cin>>c[i][j];
        if(i!=j && cmin>c[i][j]) cmin = c[i][j];
    }
    X[0]=0;
    Try(1);
    f_best==10000 ? cout<<-1 : cout<<f_best;
   // cout<<f_best;
    return 0;
}

