//https://codeforces.com/problemset/problem/600/E
#include <bits/stdc++.h>
using namespace std;

#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
//#define ld long double
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
typedef long double ld;
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




ll builtin_popcount(ll x)
{
    ll cnt = 0;
    for(ll i=60;i>=0;i--)
    {
        if((1LL<<i)&x)cnt++;
    }
    return cnt;
}

ll addmod(ll a,ll b,ll r)
{
    a%=r;
    b%=r;
    return (a+b)%r;
}
ll mulmod(ll a,ll b,ll r)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll submod(ll a,ll b)
{
    a%=mod;
    b%=mod;
    a-=b;
    if(a<0)a+=mod;
    return a%mod;
}
struct CustomCompare
{
    bool operator()(ll a,ll b)
    {
        return a>b;
    }
};
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

ll n;
vi col,ans,mx;
vvi g;
void solve(ll i,ll par,map<ll,ll> &mp)
{
    mx[i] = mp[col[i]] = 1;
    ans[i] = col[i];

    for(auto x:g[i])
    {
        if(x!=par)
        {
            map<ll,ll>mn;
            solve(x,i,mn);

            if(mp.size()<mn.size())
            {
                swap(mp,mn);
                mx[i] = mx[x] , ans[i] = ans[x];
            }

            for(auto it:mn)
            {
                ll res = it.fi;
                mp[res]+=it.se;

                if(mp[res]>mx[i])
                {
                    mx[i] = mp[res] , ans[i] =res;
                }
                else if(mp[res]==mx[i])ans[i]+=res;
            }
        }
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
cin>>n;
col = ans = mx = vi(n);
rep(i,0,n)cin>>col[i];
g = vvi(n);
rep(i,1,n)
{
    ll u,v; cin>>u>>v;
    --u,--v;
    g[u].pb(v),g[v].pb(u);
}
map<ll,ll>mp;
solve(0,-1,mp);
for(auto x:ans)cout<<x<<" ";

return 0;
}
/*
1
3 1
023l
2 3
*/
