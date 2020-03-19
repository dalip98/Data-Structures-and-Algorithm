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
ll n;
vi arr,ans;
ll bs(ll r,ll val)
{
    ll l = 0,a = -1;
    while(l<=r)
    {
        ll mid = l + (r-l)/2;
        if(ans[mid]<val)
        {
            l = mid+1;
            a= mid;
        }
        else r = mid-1;
    }
    return a;
}

ll lis()
{
    ans = vi(n+1);
    ans[0] = arr[0];
    ll len = 1;
    rep(i,1,n)
    {
        if(arr[i]<ans[0])ans[0] = arr[i];
        else if(ans[len-1]<arr[i])ans[len++] = arr[i];
        else ans[bs(len-1,arr[i])] = arr[i];
    }
    return len;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	arr = vi(n);
	rep(i,0,n)cin>>arr[i];
	cout<<lis()<<endl;
	return 0;
}
