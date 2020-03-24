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
vi pref;

void pref_function(string s)
{
    ll n = s.size();
    for(ll i =1;i<n;i++)
    {
        ll j = pref[i-1];
        while(j>0&&(s[i]!=s[j]))j=pref[j-1];

        if(s[i]==s[j])j++;
        pref[i] = j;
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s; cin>>s;
	ll n = s.size();
	pref = vi(n);
	pref_function(s);
	cout<<pref[n-1]<<endl;
	return 0;
}
