#include<bits/stdc++.h>
using namespace std;
int main()
    {
        int t;
        cin>>t;
        while (t--)
        {
            int n;
        cin>>n;
        vector<int>vec(n);
        for (int i=0;i<n;i++)
        {
            cin>>vec[i];
            vec[i] = -vec[i];
        }

        vector<int>result={vec[0]};
        vector<int>result1={};
        int idx=0;
        while ((vec[idx]-vec[0]) %2==0)
        {
            idx++;
        }
        result1.push_back(vec[idx]);
        for (int i=1;i<n;i++)
        {
            if (i>idx)
            {
              auto it = upper_bound(result1.begin(),result1.end(),vec[i]);
            if (it == result1.end())
            {
                if ((vec[i] - result1.back())%2!=0)
                {
                    result1.push_back(vec[i]);
                }

            }
            else
            {
                 if ((*it - vec[i]) % 2 ==0)
                {

                    *it = vec[i];
                }
            }

            }
            auto it = upper_bound(result.begin(),result.end(),vec[i]);
            if (it == result.end())
            {
                if ((vec[i] - result.back())%2!=0)
                {
                    result.push_back(vec[i]);
                }

            }
            else
            {

                 if ((*it - vec[i]) % 2 ==0)
                {

                    *it = vec[i];
                }
            }

        }

                cout<<max(result.size(),result1.size())<<"\n";
        }
    }
