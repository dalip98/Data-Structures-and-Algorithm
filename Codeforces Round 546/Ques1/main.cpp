#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n; cin>>n;
	vector<pair<ll,ll> >arr(n);
	for(ll i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    ll k ,temp=0; cin>>k;
    for(ll i=0;i<n;i++)
    {
        if(arr[i].first<=k&&arr[i].second>=k)
        {
            temp = i;
            break;
        }
    }
    //cout<<temp<<endl;
    cout<<n-temp<<endl;
	return 0;
}
