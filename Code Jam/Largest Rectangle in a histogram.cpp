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
typedef vector<pair<ll,ll>> vpi;
typedef vector<ll> vi;
typedef vector<vi> vvi;

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
    ll n; cin>>n;
    vi arr(n);
    rep(i,0,n)cin>>arr[i];

    stack<ll>s;
    ll i =0,mx = 0;
    while(i<n)
    {
        if(s.empty()||(arr[s.top()]<=arr[i]))s.push(i++);
        else
        {
            ll temp = s.top();
            s.pop();
            ll area = arr[temp]*(s.empty()?i:i-s.top()-1);
            mx = max(mx,area);
        }
    }
    while(!s.empty())
    {
        ll temp = s.top();
        s.pop();
        ll area = arr[temp]*(s.empty()?i:i-s.top()-1);
        mx = max(mx,area);
    }
    cout<<mx<<endl;
    return 0;
}
