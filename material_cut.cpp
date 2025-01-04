#include<bits/stdc++.h>
#define N 11
using namespace std;
int H,W,n;
int h[N], w[N];
bool Visit[N][N]={};

bool Check(int x,int y,int k,int o){
    int hk = h[k], wk = w[k];
    if(o==1) {hk=wk; wk=h[k];}
    for(int i=x;i>x-hk;i--)
    for(int j=y;j>y-wk;j--){
        if (Visit[i][j]) return false;
    }
    return true;
}

void Mask(int x, int y, int k, int o, bool v){
    int hk = h[k], wk = w[k];
    if(o==1) {hk=wk; wk=h[k];}
    for(int i=x;i>x-hk;i--)
    for(int j=y;j>y-wk;j--){
        Visit[i][j]=v;
    }
}

void Result(){
    cout<<1;
    exit(0);
}
void Try(int k){
    int hk=h[k], wk=w[k];
    for(int o=0;o<=1;o++){
        if(o==1){hk=w[k];wk=h[k];}
        for(int x=hk;x<=H;x++)
        for(int y=wk;y<=W;y++){
            if(Check(x,y,k,o)){
                Mask(x,y,k,o,true);
                if(k==n) Result();
                else Try(k+1);
                Mask(x,y,k,o,false);
            }
        }
    }
}
int main()
{
    cin>>H>>W;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i]>>w[i];
    Try(1);
    cout<<0;
    return 0;
}
