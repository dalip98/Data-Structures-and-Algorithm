#include <bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;

#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define mod 1000000007
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF LONG_MAX
#define PI 3.1415926535897932384626
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define rep(x,j,n)for(int x=j;x<n;x++)
#define all(x) (x).begin(), (x).end()

typedef vector<pair<ll,ll>> vpi;
typedef vector<ll> vi;
typedef vector<vi> vvi;

bool prime(ll n)
{
	if(n<=1)return false;
	if(n<=3)return true;
	if(n%2==0||n%3==0)return false;
	for(ll i=5;i*i<=n;i+=6)
	{
		if(n%i==0||n%(i+2)==0)return false;
	}
	return true;
}

ll modexp(ll a,ll b,ll m)
{
	ll r=1;
	a=a%m;
	while(b>0)
	{
		if(b&1)r=(r*a)%m;
		b = b>>1;
		a=(a*a)%m;
	}
	return r%m;
}

ll addmod(ll a,ll b)
{
    if(a+b<mod)return a+b;
    else return a+b-mod;
}
ll mulmod(ll a,ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll modinv(ll a)
{
    return modexp(a,mod-2,mod);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n; cin>>n;
	vi arr(n);
	rep(i,0,n)cin>>arr[i];
	ll len = sqrt(n)+1;
	vi range(len);
	rep(i,0,n)range[i/len]+=arr[i];
	ll q; cin>>q;
	while(q--)
    {
        ll l,r,sum=0;cin>>l>>r;
        ll cl = l/len, cr = r/len;
        if(cl==cr)
        {
            rep(i,l,r+1)sum+=arr[i];
        }
        else
        {
            ll e=(cl+1)*len-1;
            for(ll i =l;i<=e;i++)sum+=arr[i];
            for(ll i =cl+1;i<=cr-1;i++)sum+=range[i];
            for(ll i=cr*len;i<=r;i++)sum+=arr[i];
        }
        cout<<sum<<endl;

    }
	return 0;
}
/*
6
1 2 3 4 5 -6
*/
