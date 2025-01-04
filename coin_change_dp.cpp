#include<bits/stdc++.h>
#define N 1001
using namespace std;
int n,X, d[N];
int M[N][N]={};
const int VC = 100000;

int Mincoin(int i, int x){
    if(x==0) return 0;
    if(x<0 || i==0) return VC;
    if(M[i][x]!= 0) return M[i][x];

    int res=VC;
    res = min(res, Mincoin(i,x-d[i])+1);
    res = min(res, Mincoin(i-1,x));
    M[i][x]=res;
    return res;
}

void Truy_vet(int i, int x) {
    if (x <= 0 || i == 0) return;

    // Kiểm tra nếu lấy đồng tiền thứ i
    if (x - d[i] >= 0 && M[i][x] == M[i][x - d[i]] + 1) {
        cout << d[i] << ' ';
        Truy_vet(i, x - d[i]);
    } else { // Ngược lại, bỏ qua đồng tiền thứ i
        Truy_vet(i - 1, x);
    }
}
int main()
{
    cin>>n>>X;
    for(int i=1;i<=n;i++) cin>>d[i];
    cout<<Mincoin(n,X);

    cout<<endl;
    Truy_vet(n,X);
    return 0;
}
