#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> result = {a[1]};
    for(int i=2;i<=n;i++){
        auto it = lower_bound(result.begin(), result.end(), a[i]);
        if(it == result.end()){
            result.push_back(a[i]);
        }else{
            *it = a[i];
        }
    }
    cout<<result.size();
    return 0;
}
