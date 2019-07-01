#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll x = (n*(n+1))/2;

        for(ll i=0;i<n-1;i++)
        {
            ll tmp; cin>>tmp;
            x-=tmp;
        }
        cout<<x<<endl;
    }
    return 0;
}
