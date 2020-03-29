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


ll solve(ll n,string s,string e)
{
    ll dp[503][53][2];
    ll tr[53][26];
    reverse(all(e));
    for(ll i =0;i<e.size();i++)
    {
        string tmp = e.substr(0,i);
        for(ll j = 0;j<26;j++)
        {
            string tmp2 = tmp + (char)(j+'a');
            for(ll k= i+1;;k--)
            {
                if(tmp2.substr(i+1-k)==e.substr(0,k))
                {
                    tr[i][j] = k;
                    break;
                }
            }
        }
    }
    for(ll i =0;i<=n;i++)
        for(ll j =0;j<e.size();j++)dp[i][j][0] = 0,dp[i][j][1] = 0;

    dp[n][0][1] = 1;
    for(ll i= n-1;~i;i--)
    {
        for(ll j=0;j<e.size();j++)
        {
            for(ll k = 0;k<26;k++)
            {
                for(ll l :{0,1})
                {
                    ll nl;
                    if(k<s[i]-'a')nl = 1;
                    else if(k>s[i]-'a')nl = 0;
                    else nl = l;
                    dp[i][tr[j][k]][nl] = (dp[i+1][j][l]+dp[i][tr[j][k]][nl])%mod;
                }
            }
        }
    }
    ll ans = 0;
    for(ll j = 0;j<e.size();j++)
        ans+=(dp[0][j][1]);
    return ans%mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n; cin>>n;
	string s1,s2,evil; cin>>s1>>s2>>evil;
	ll ans = solve(n,s2,evil);
	ll ok = 1;
	for(ll i =0;i<n&&ok;i++)ok = s1[i]=='a';

	if(!ok)
    {
        for(ll i= n-1;;i--)
        {
            if(s1[i]>'a')
            {
                --s1[i];
                break;
            }
            s1[i] = 'z';
        }
        ans = (ans+mod-solve(n,s1,evil))%mod;
    }
    cout<<ans<<endl;
	return 0;
}
/*
6
1 2 3 4 5 -6
*/
