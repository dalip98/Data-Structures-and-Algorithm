#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ll n,t; cin>>n>>t;
    vector<pair<ll,ll> >arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    ll bs = -1 , mn =INT_MAX;
    for(ll i=0;i<n;i++)
    {
        ll it = fabs(arr[i].first-t),j=0;
        while(1)
        {
            if(arr[i].first+j*arr[i].second<t)
            {
                j++;
                continue;
            }
            if(fabs(arr[i].first+j*arr[i].second-t)<=it)
            {
                it = fabs(arr[i].first+j*arr[i].second - t);
                j++;
            }
            else
                break;

        }
        if(mn>=it)
        {
            mn=it;
            bs=i;
        }
    }
    cout<<bs+1<<endl;
    return 0;
}
