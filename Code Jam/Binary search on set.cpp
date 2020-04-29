//https://codeforces.com/problemset/problem/706/D
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
    if(a.fi==b.fi)return a.se>b.se;
    return a.fi<b.fi;
}

vi par,vis;

ll dfs(ll x)
{
    vis[x] = 2;
    ll val;
    if(x==par[x]||vis[par[x]] ==1)val = 0;
    else if(vis[par[x]] ==2)val = x;
    else val = dfs(par[x]);
    vis[x] = 1;
    return val;
}
int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(0);cout.tie(0);
ll q; cin>>q;
map<ll,ll>mp;
set<ll>st;
st.insert(0);
while(q--)
{
    char c;cin>>c;
    ll x; cin>>x;
    if(c=='+')
    {
        mp[x]++;
        if(mp[x]==1)st.insert(x);
    }
    else if(c=='-')
    {
        mp[x]--;
        if(mp[x]==0)st.erase(x);
    }
    else
    {
        unsigned int y = ~x;
        ll l = 0 , r = 4294967295;
        for(ll bit = 31;bit>=0;bit--)
        {
            if(y&(1LL<<bit))
            {
                if(st.lower_bound(l+(1LL<<bit))!=st.end()&&*st.lower_bound(l+(1LL<<bit))<=r)l+=(1<<bit);
                else r-=(1LL<<bit);
            }
            else
            {
                if(st.lower_bound(l)!=st.end()&&*st.lower_bound(l)<l+(1LL<<bit))r-=(1LL<<bit);
                else l+=(1LL<<bit);
            }
            //cout<<l<<" "<<r<<endl;
        }
        cout<<(l^x)<<endl;
    }
}
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
