#include <bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;

#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define mod 998244353
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
bool comp(pair<ll,ll>a,pair<ll,ll>b)
{
    return a.fi>b.fi;
}
ll n,m;
vvi g;
vi dist;

void djikstra(ll s)
{
    dist = vi(n,mod);
    vector<ll>par(n,-1);
    set<pair<ll,ll> >st;
    dist[s] = 0;
    st.insert({0,s});
    while(!st.empty())
    {
        auto v = *st.begin();
        st.erase(st.begin());
        for(auto to:g[v.se])
        {
            ll u = to,len = v.fi;
            if(1+len<dist[u])
            {
                st.erase({dist[u],u});
                dist[u] =1+len;
                par[u] = v.se;
                st.insert({dist[u],u});
            }
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    g = vvi(n);
    rep(i,0,m)
    {
        ll u,v;cin>>u>>v;
        --u,--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    djikstra(0);
    for(auto x:dist)cout<<x<<" ";
    cout<<endl;
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
