#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;
int main()
{
	ios::sync_with_stdio(0);

	ll n,t; cin>>n>>t;
	vector<pair<ll,ll> >arr(n);
	for(ll i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    ll mn = INT_MAX ,id =0;
    for(ll i=0;i<n;i++)
    {
        ll j=0;
        while(1)
        {

            if(arr[i].first+j*arr[i].second >=t)
            {
                if(arr[i].first + j*arr[i].second-t < mn)
                {
                    mn = arr[i].first + j*arr[i].second -t;
                    id = i;
                }
                break;
            }
            j++;
        }
    }
    cout<<id+1<<endl;

	return 0;
}
