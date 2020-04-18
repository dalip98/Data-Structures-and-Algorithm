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
typedef pair<ll,ll> pi;

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
bool comp(pair<ll,ll>a,pair<ll,ll>b)
{
    return a.fi>b.fi;
}
ll n,m;
vector<pair<ll,pi> >edge,res;
vi par , ra;

void make_set(ll i)
{
    par[i] = i;
    ra[i] = 0;
}

ll find_set(ll v)
{
    if(par[v]==v)return v;
    return (par[v]= find_set(par[v]));
}

void union_sets(ll a,ll b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(ra[a]<ra[b])swap(a,b);
        par[b]=a;
        if(ra[a]==ra[b])ra[a]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    par = ra = vi(n);
    rep(i,0,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        --u,--v;
        edge.pb({w,{u,v}});
    }
    rep(i,0,n)make_set(i);
    sort(all(edge));
    ll ans = 0;
    for(auto x:edge)
    {
        if(find_set(x.se.fi)!=find_set(x.se.se))
        {
            ans+=x.fi;
            res.pb(x);
            union_sets(x.se.fi,x.se.se);
        }
    }
    cout<<ans<<endl;
    return 0;

}
/*
1
4
4 2
10 3
3 4
9 2
*/
