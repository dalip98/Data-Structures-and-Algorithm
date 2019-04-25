#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n,m; cin>>n>>m;
	multiset<ll>arr[1003][2];

	for(ll i=0;i<n;i++)
	{
	    for(ll j=0;j<m;j++)
        {
            ll a; cin>>a;
            arr[i+j][0].insert(a);
        }
	}

	for(ll i=0;i<n;i++)
	{
	    for(ll j=0;j<m;j++)
        {
            ll a; cin>>a;
            arr[i+j][1].insert(a);
        }
	}

	for(ll i=0;i<1003;i++)
    {
        if(arr[i][0]!=arr[i][1])
        {
            cout<<"nO"<<endl;
            return 0;
        }
    }
    cout<<"yEs"<<endl;

	return 0;
}
