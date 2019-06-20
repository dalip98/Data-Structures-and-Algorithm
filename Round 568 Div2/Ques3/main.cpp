#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n,m,sum=0; cin>>n>>m;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
        cin>>arr[i];
    for(ll i=0;i<n;i++)
    {
        ll ans = 0;
        if(sum+arr[i]>m)
        {
            vector<ll>temp;
            for(ll j=0;j<i;j++)
            {
                temp.push_back(arr[j]);
            }
            sort(temp.begin(),temp.end(),greater<int>());

            ll x= sum+arr[i];

            for(ll j=0;j<i;j++)
            {
                if(x>m)
                    {
                        ans++;
                    x-=temp[j];
                    }
            }
            cout<<ans<<" ";

            }
        else
            cout<<0<<" ";

        sum+=arr[i];

    }
	return 0;
}
