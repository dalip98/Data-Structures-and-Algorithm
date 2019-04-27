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
	vector<ll>arr(n);
	for(ll i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll ans=0,j=0;
    for(ll i=0;i<n;i++)
    {
        while(j<n&&(arr[j]-arr[i]<=5))
        {
            ++j;
            ans = max(ans , j-i);
        }
    }
    cout<<ans<<endl;
	return 0;
}
