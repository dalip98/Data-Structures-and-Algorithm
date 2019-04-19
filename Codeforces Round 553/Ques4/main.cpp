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
	vector<pair<ll,ll> >arr(n) ,brr(n);

	for(ll i=0;i<n;i++)
    {
        cin>>arr[i].second>>arr[i].first;
        brr[i].second = i;
        brr[i].first = arr[i].second - arr[i].first;
    }
    sort(brr.begin() , brr.end());
    ll sum = 0;

    for(ll i=0;i<n;i++)
    {
        ll x = brr[i].second;
        sum+= arr[x].first*n - arr[x].second +(n-i)*(arr[x].second - arr[x].first);
    }
    cout<<sum<<endl;
	return 0;
}
