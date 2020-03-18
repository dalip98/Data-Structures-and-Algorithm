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
		if(b&1)
		    r=(r*a)%m;
		b>>1;
		a=(a*a)%m;
	}
	return r%m;
}
ll n,q;
ll mx = 1e5;
vi arr(mx),ql(mx),qr(mx),qry(mx),ans(mx),ft(mx);

struct event{
    ll y,t,i;
    bool operator<(const event &o) const{
        return mp(y,t)<mp(o.y,o.t);
    }
};

void update(ll i,ll x)
{
    for(++i;i<n;i+=i&-i)
    {
        ft[i]+=x;
    }
}

ll query(ll i)
{
    ll r = 0;
    for(;i;i-=i&-i)
        r+=ft[i];
    return r;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll t; cin>>t;
	while(t--)
    {
        cin>>n>>q;
        rep(i,0,n)cin>>arr[i];
        rep(i,0,q)
        {
            cin>>ql[i]>>qr[i]>>qry[i];
            --ql[i],--qr[i];
        }
        vector<event>v;
        rep(i,0,n-1)
        {
            v.pb({min(arr[i],arr[i+1]),1,i});
            v.pb({max(arr[i],arr[i+1]),3,i});
        }
        rep(i,0,q)v.pb({qry[i],2,i});

        sort(v.begin(),v.end());

        for(event e:v)
        {
            if(e.t==1)
            {
                update(e.i,1);
            }
            else if(e.t==2)
            {
                ans[e.i] = query(qr[e.i]) - query(ql[e.i]);
            }
            else update(e.i,-1);
        }
        rep(i,0,q)cout<<ans[i]<<endl;
    }
	return 0;
}
