#include<bits/stdc++.h>
#define N 1000001
using namespace std;
int a[N], seg_tree[2*N];

//pos : seg_tree
void construct_Tree(int l, int r, int pos){
    if(l==r) {seg_tree[pos] = a[l]; return;}
    int mid = (l+r)/2;
    construct_Tree(l,mid,2*pos);
    construct_Tree(mid+1,r,2*pos+1);
    seg_tree[pos] = min(seg_tree[2*pos], seg_tree[2*pos+1]);
}

int RMQ(int ql, int qr, int l, int r, int pos){
    // total overlap
    if(ql<=l && r<=qr) return seg_tree[pos];
    // no overlap
    if(qr<l || r<ql) return N;
    // partial overlap
    int mid = (l+r)/2;
    int tmp1 = RMQ(ql,qr,l,mid,2*pos);
    int tmp2 = RMQ(ql,qr,mid+1,r,2*pos+1);
    return min(tmp1,tmp2);

}
int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    // Xây dựng segment tree
    fill(seg_tree+1, seg_tree + 2*n +1, N);
    construct_Tree(1,n,1);

    int m; cin>>m;
    int tmp1, tmp2,Q=0;
    for(int i=0;i<m;i++){
        cin>>tmp1>>tmp2;
        Q += RMQ(tmp1,tmp2,1,n,1);
    }
    cout<<Q;
    return 0;
}
