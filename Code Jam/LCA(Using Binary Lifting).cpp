#include <bits/stdc++.h>
using namespace std;

#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define mod 1000000007
#define inf 100000000000010
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
typedef pair<ll,ll> pi;

bool isprime(ll n)
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

struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs < rhs;
    }
};

bool comp(pair<ll, ll>a,pair<ll,ll>b)
{
    return a.fi>=b.fi;
}

ll builtin_popcount(ll x)
{
    ll cnt = 0;
    for(ll i=60;i>=0;i--)
    {
        if((1LL<<i)&x)cnt++;
    }
    return cnt;
}

ll addmod(ll a,ll b)
{
    a%=mod;
    b%=mod;
    return (a+b)%mod;
}
ll mulmod(ll a,ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
/*
const int mxn = 5*(1e6) +10;
vi spf(mxn);
void sieve()
{
    for(ll i =0;i<mxn;i++)spf[i]  = i;
    for(ll i=2;i<mxn;i+=2)spf[i] = 2;
    for(ll i = 3;i*i<mxn;i++)
    {
        if(spf[i]==i)
        {
            for(ll j = i*i;j<mxn;j+=i)
            {
                if(spf[j]==j)spf[j] = i;
            }
        }
    }
}
*/
ll n,m;
ll height ;
vi tin,tout;
ll timer;
vvi up,g;
void dfs(ll s,ll p)
{
    tin[s]=++timer;
    up[s][0] = p;
    for(ll i=1;i<=height;i++)
    {
        up[s][i]= up[up[s][i-1]][i-1];
    }
    for(auto x:g[s])
    {
        if(x!=p)dfs(x,s);
    }
    tout[s] = ++timer;
}
bool isancestor(ll u,ll v)
{
    return (tin[u]<=tin[v])&&(tout[u]>=tout[v]);
}

ll lca(ll u,ll v)
{
    if(isancestor(u,v))return u;
    if(isancestor(v,u))return v;
    for(ll i=height;i>=0;--i)
    {
        if(!isancestor(up[u][i],v))u=up[u][i];
    }
    return up[u][0];
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
cin>>n>>m;
g = vvi(n);
rep(i,0,m)
{
    ll u,v; cin>>u>>v;
    u--,v--;
    g[u].pb(v),g[v].pb(u);
}
tin.resize(n),tout.resize(n);
height = ceil(log2(n));
timer = 0;
up = vector<vector<ll> >(n,vector<ll>(height+1));
dfs(0,0);
ll q; cin>>q;
while(q--)
{
    ll u,v; cin>>u>>v;
    u--,v--;
    cout<<lca(u,v)<<endl;
}
return 0;

}
/*
23 5
10 3 3
2 1 4 11 8 10 5 6 7 9 12 3 14 13 16 18 21 15 17 19 20 23 22
4 6 3 18 23
*/
