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

bool comp(pair<ll, ll>a,pair<ll,ll>b)
{
    return a.fi>b.fi;
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
const int mxn = 1e5 + 10;
ll trie[mxn][26];
ll nxt = 1;
bool is_true[mxn];
void insert_trie(string s)
{
    ll node = 0;
    rep(i,0,s.size())
    {
        if(trie[node][s[i]-'a']==0)trie[node][s[i]-'a'] = nxt++;
        node = trie[node][s[i]-'a'];
    }
    is_true[node] = true;
}
string longest_common_prefix()
{
    ll node = 0;
    string ans= "";
    while(1)
    {
        if(is_true[node])break;
        ll cnt = 0,temp,c;
        bool flag = false;
        rep(i,0,26)
        {
            if(trie[node][i])cnt++,temp = trie[node][i],c = i;
        }
        if(cnt>1)break;
        node = temp;
        ans.pb('a'+c);
    }
    return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
ll n; cin>>n;
vector<string>arr(n);
rep(i,0,n)
{
    cin>>arr[i];
    insert_trie(arr[i]);
}
cout<<longest_common_prefix()<<endl;
return 0;
}
/*
23 5
10 3 3
2 1 4 11 8 10 5 6 7 9 12 3 14 13 16 18 21 15 17 19 20 23 22
4 6 3 18 23
*/
