#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

ll query(ll l, ll r){
	cout<<1<<' '<<(r-l+1)<<' '<<1<<' ';
	for(;l<=r;++l)cout<<l<<' ';
	cout<<'\n'<<flush;
	cin>>r;
	return r;
}

void solve(){
	ll n;
	cin>>n;
	ll l=2,r=n;
	ll dist=query(2,n);
	while(l!=r){
		ll m=(l+r)>>1;
		if(query(l,m)==dist)r=m;
		else l=m+1;
	}
	cout<<1<<' '<<n-1<<' ';
	cout<<l<<' ';
	for(ll i=1; i<=n; ++i)if(i!=l)cout<<i<<' ';
	cout<<'\n'<<flush;
	ll res;
	cin>>res;
	cout<<"-1 "<<res<<'\n'<<flush;
}

int main()
{
    ios::sync_with_stdio(0);
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
