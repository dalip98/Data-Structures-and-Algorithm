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
ll n;
vi arr;
vpi tree1,tree2;

pair<ll,ll> addpair(pair<ll,ll>a,pair<ll,ll>b)
{
    pair<ll,ll>ans;
    ans.fi = a.fi+b.fi;
    ans.se = max(a.se,a.fi+b.fi);
    return ans;
}
void build(ll l ,ll r,ll v,vpi &tree,ll p)
{
    if(l==r)tree[v].fi = arr[l]*p,tree[v].se = arr[l]*p;
    else
    {
        ll mid = l +(r-l)/2;
        build(l,mid,2*v,tree,p);
        build(mid+1,r,2*v+1,tree,p);
        tree[v].fi = tree[2*v].fi+tree[2*v+1].fi;
        tree[v].se = max(tree[2*v].se,tree[2*v].fi+tree[2*v+1].se);
    }
}

pair<ll,ll> query(ll tl,ll tr,ll ql,ll qr,ll v,vpi tree)
{
    if(ql>qr)return {0,0};
    if(tl==ql&&tr==qr)return tree[v];
    ll mid = tl+(tr-tl)/2;

    return addpair(query(tl,mid,ql,min(qr,mid),2*v,tree),query(mid+1,tr,max(ql,mid+1),qr,2*v+1,tree));

}

void update(ll v,ll tl,ll tr,ll pos,ll new_val,vpi &tree)
{
    if(tl==tr)tree[v].fi = new_val,tree[v].se= new_val;
    else
    {
        ll mid = tl+(tr-tl)/2;
        if(pos<=mid)update(2*v,tl,mid,pos,new_val,tree);
        else
        {
            update(2*v+1,mid+1,tr,pos,new_val,tree);
        }
        tree[v] = addpair(tree[2*v],tree[2*v+1]);
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll q;
	cin>>n>>q;
	arr = vi(n);
	tree1 = vpi(4*n),tree2 = vpi(4*n);
	rep(i,0,n)cin>>arr[i];
	build(0,n-1,1,tree1,1);
	build(0,n-1,1,tree2,-1);

	while(q--)
    {
        char c; cin>>c;
        ll x,y; cin>>x>>y;
        x--,y--;
        if(c=='Q')
        {
            auto a = query(0,n-1,0,x,1,tree2),b  = query(0,n-1,y,n-1,1,tree1);
            auto c = query(0,n-1,0,y,1,tree1);
            cout<<c.fi+b.se+a.fi<<endl;
        }
        else
        {
            update(1,0,n-1,x,y+1,tree1);
            update(1,0,n-1,x,(-1)*(y+1),tree2);
        }
    }
	return 0;
}
/*
6
1 2 3 4 5 -6
*/
