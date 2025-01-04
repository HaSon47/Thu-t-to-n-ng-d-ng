//C++
#include<iostream>
using namespace std;
int n,K,Q;
int d[13];
int c[13][13];
int Y[6], X[13];
int f=0, f_best=100000, seg = 0, nbR =0, cmin=100000;
bool Visit[13]={};
int load[6] ={};
bool Check_x(int v, int k){
    if ((v>0)&&(Visit[v])) return false;
    if (load[k]+d[v]>Q) return false;
    return true;
}
void up_best(){
    if(f_best >f) f_best = f;
}
void Try_x(int s, int k){
    if(s==0){
        if(k<K) Try_x(Y[k+1], k+1);
        return;
    }
    for(int v=0;v<=n;v++){
        if (Check_x(v,k)){
            X[s]=v; Visit[v]= true; f += c[s][v];
            load[k]+=d[v]; seg++;
            if (v>0) {
                if (f+(n+nbR-seg)*cmin < f_best) Try_x(v,k);
            }else if(k==K){
                if(seg == n+nbR) up_best();
            }else if (f+(n+nbR-seg)*cmin < f_best) Try_x(Y[k+1], k+1);

            Visit[v] = false; f -= c[s][v];
            load[k]-=d[v]; seg--;
        }
    }
}
bool Check_y(int k,int i){
    if (k==1) return true;

    if(Y[k-1]==0){
        if((k==K)&&(i==0)) return false;
        return true;
    }

    if(Y[k-1]<i) return true;
    return false;

}
void Try_y(int k){
    for(int i=0;i<=n;i++){
        if (Check_y(k,i)){
            Y[k]=i; f+= c[0][i]; Visit[i] = true; load[k] = d[i];
            if(i>0) seg++;
            if(k==K) {nbR=seg; Try_x(Y[1],1);}
            else Try_y(k+1);
            Visit[i] = false; f-= c[0][i];
        }
    }
}
int main()
{
    cin>>n>>K>>Q;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) {
                cin>>c[i][j];
                if((i!=j)&&(cmin>c[i][j])) cmin = c[i][j];
        }
    Try_y(1);
    cout<<f_best;
    return 0;
}

