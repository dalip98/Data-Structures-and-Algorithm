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
		if(b&1)
		    r=(r*a)%m;
		b>>1;
		a=(a*a)%m;
	}
	return r%m;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s; cin>>s;
	ll n = s.size();
	vi d1(n),d2(n);

	for(ll i=0,l=0,r=-1;i<n;i++)
    {
        ll k = (i>r)?1: min(d1[l+r-i],r-i+1);
        while(0<=i-k&&i+k<n&&(s[i-k]==s[i+k]))k++;
        d1[i] = k--;
        if(i+k>r)
        {
            r = i+k;
            l = i-k;
        }
    }

    for(ll i=0,l=0,r=-1;i<n;i++)
    {
        ll k = (i>r)?0:min(d2[l+r+1-i],r-i+1);
        while(0<=i-k-1&&i+k<n&&(s[i-k-1]==s[i+k]))k++;
        d2[i] = k--;
        if(i+k>r)
        {
            r = i+k;
            l = i-k-1;
        }
    }
    for(auto x:d1)cout<<x<<" ";
    cout<<endl;
    for(auto x:d2)cout<<x<<" ";
    cout<<endl;
	return 0;
}
