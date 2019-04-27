#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n,k; cin>>n>>k;
	vector<ll>arr(k+1);
	for(ll i=0;i<n;i++)
    {
        ll a; cin>>a;
        arr[a%k]++;
    }
    ll sum=0;
    for(ll i=0;i<=k;i++)
    {
        if(arr[i]!=0)
        {
            sum+=min(arr[i] , arr[k-i]);
        }
    }
    cout<<2*(sum/2+arr[0]/2)<<endl;
	return 0;
}
