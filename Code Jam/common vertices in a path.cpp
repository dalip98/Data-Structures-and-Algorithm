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
ll n,m,t;
vvi g;
vi dep,par;
vi tin,tout;

void dfs(ll v,ll p =-1,ll d = 0)
{
    par[v] = p;
    dep[v] = d;
    tin[v] = t++;
    for(auto to:g[v])
    {
        if(to==p)continue;
        dfs(to,v,d+1);
    }
    tout[v]=t++;
}

bool isAns(ll v,ll u)
{
    return (tin[v]<=tin[u])&&(tout[v]>=tout[u]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	g = vvi(n);
	dep = par = vi(n);
	tin = tout = vi(n);
	rep(i,0,n-1)
	{
	    ll u,v; cin>>u>>v;
	    --u,--v;
	    g[u].pb(v);
	    g[v].pb(u);
	}
	dfs(0);
	//cout<<"okay\n";
	for(ll i =0;i<m;i++)
	{
	    ll k; cin>>k;
	    vi arr(k);
	    rep(i,0,k)cin>>arr[i],--arr[i];

	    ll u = arr[0];
	    for(auto x:arr)if(dep[u]<dep[x])u=x;
	    for(auto &it:arr)
        {
            if(it==u)continue;
            if(par[it]!=-1)it = par[it];
        }
        bool ok= true;
        for(auto it:arr)ok&=isAns(it,u);
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
	}
	return 0;
}
/*
6
1 2 3 4 5 -6
*/
