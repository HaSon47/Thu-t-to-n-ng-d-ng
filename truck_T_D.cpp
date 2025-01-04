//C++
#include<bits/stdc++.h>
#define N 1001
using namespace std;
int n, T,D;
int a[N], t[N];
int S[101][N]={}; //S[T][n]
int res=0;
int main()
{
    cin>>n>>T>>D;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>t[i];

    for(int i=t[1];i<=T;i++) S[i][1]=a[1];
    res = S[T][1];

    for(int k=2;k<=n;k++){
        for(int tk=t[k];tk<=T;tk++){
            int tmp_max=0, head = max(1,k-D);
            for(int tmp=head; tmp<=k-1;tmp++){
                tmp_max = max(tmp_max, S[tk-t[k]][tmp]);
            }
            S[tk][k] = tmp_max + a[k];
        }
        res = max(res, S[T][k]);
    }
    cout<<res;
}

