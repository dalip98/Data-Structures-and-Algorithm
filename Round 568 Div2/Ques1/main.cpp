#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	vector<ll>arr(3);
	for(ll i=0;i<3;i++)
        cin>>arr[i];
    ll d; cin>>d;
    sort(arr.begin(),arr.end());
    ll a = fabs(arr[1]-arr[0]) , b= fabs(arr[2] - arr[1]);
    ll ans = 0;
    if(a<d)
    {
        ans+=d-a;
    }
    if(b<d)
        ans+=d-b;
    cout<<ans<<endl;
	return 0;
}
