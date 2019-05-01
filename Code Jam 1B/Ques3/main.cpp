#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll t; cin>>t;
	ll z=t;
	while(t--)
    {
        ll n,k; cin>>n>>k;
        vector<pair<ll,ll> >arr(n);
        vector<pair<ll,ll> >brr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i].first;
        for(ll i=0;i<n;i++)
            cin>>brr[i].first;
        ll mx=0 , nx = 0;
        for(ll i=0;i<n;i++)
        {
            arr[i].second = max(arr[i].first , mx);
            mx = arr[i].second;
            brr[i].second = max(brr[i].first , nx);
            nx = brr[i].second;
        }
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=i;j<n;j++)
            {
                ll x = arr[i].first ,y =brr[i].first;
                for(ll d=i;d<=j;d++)
                {
                    x = max(x , arr[d].first);
                    y = max(y , brr[d].first);
                }
                //cout<<fabs(x-y)<<endl;
                if(fabs(x-y)<=k)
                    sum++;
            }
        }
        cout<<"Case #"<<z-t<<": ";
        cout<<sum<<endl;

    }
	return 0;
}
