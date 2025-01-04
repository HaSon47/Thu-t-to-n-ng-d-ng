//C++
#include<iostream>
#include<vector>
using namespace std;
int n,m;
int res = 1000000;
vector<int> C[31];
bool conflict[31][31] = {};
int load[11] = {};
int x[31]={};
void Input(){
    cin>>m>>n;
    int k,tmp;
    for(int i=1;i<=m;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>tmp;
            C[tmp].push_back(i);
        }
    }
    int tmp2;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>tmp>>tmp2;
        conflict[tmp][tmp2]= true;
        conflict[tmp2][tmp]= true;
    }
}
bool Check(int k, int t){
    int co=0;
    for(int i=0;i<C[k].size();i++){
        if(C[k][i]==t){
            co++; break;
        }
    }
    if (co==0) return false;
    for(int i=1;i<=k;i++){
        if(x[i]==t && conflict[i][k]) return false;
    }
    return true;
}
void Update_best(){
    int s=0;
    int ma=0;
    for(int i=1;i<=m;i++){
        s += load[i];
        ma = max(ma, load[i]);
    }
    if((s==n) && (ma<res)) res=ma;
}
void Try(int k){
    for(int t=1;t<=m;t++){
        if(Check(k,t)){
            x[k] = t;
            load[t]++;
            if(k==n) Update_best();
            else if(load[t]<res) Try(k+1);
            load[t]--;
            x[k]=0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Input();
    Try(1);
    res==1000000? cout<<-1 : cout<<res;
    return 0;
}

