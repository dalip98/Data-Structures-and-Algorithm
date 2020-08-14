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

bool comp(pair<pi, ll>a,pair<pi,ll>b)
{
    if(a.fi.fi==b.fi.fi)return a.fi.se<b.fi.se;
    return a.fi.fi<b.fi.fi;
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
void count_sort(vi &p, vi &c)
{
    ll n = p.size();
    vi cnt(n,0),pos(n,0);
    rep(i,0,n)cnt[c[i]]++;
    vi p_new(n);
    pos[0] = 0;
    rep(i,1,n)pos[i] = pos[i-1]+cnt[i-1];
    for(auto x:p)
    {
        ll i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);

string s; cin>>s;
s+="$";
ll n = s.size();
vi p(n) , c(n);
vector<pair<char,ll> >arr(n);
rep(i,0,n)arr[i] = {s[i],i};
sort(all(arr));
rep(i,0,n)p[i] = arr[i].se;
c[p[0]] = 0;
rep(i,1,n)
{
    if(arr[i].fi==arr[i-1].fi)
    {
        c[p[i]] = c[p[i-1]];
    }
    else c[p[i]] = c[p[i-1]]+1;
}
ll  k = 0;
while((1<<k)<n)
{
    rep(i,0,n)
    {
        p[i] = (p[i]-(1<<k)+n)%n;
    }
    count_sort(p,c);
    vi c_new(n);
    c_new[p[0]] = 0;
    rep(i,1,n)
    {
        pi now = {c[p[i]] ,c[(p[i]+(1<<k))%n]};
        pi prev = {c[p[i-1]] ,c[(p[i-1]+(1<<k))%n]};
        if(now==prev)c_new[p[i]] = c_new[p[i-1]];
        else c_new[p[i]] = c_new[p[i-1]]+1;
    }
    c  = c_new;
    k++;
}
rep(i,0,n)
{
    cout<<p[i]<<" "<<s.substr(p[i],n-p[i])<<endl;
}
return 0;
}
/*
23 5
10 3 3
2 1 4 11 8 10 5 6 7 9 12 3 14 13 16 18 21 15 17 19 20 23 22
4 6 3 18 23
*/
