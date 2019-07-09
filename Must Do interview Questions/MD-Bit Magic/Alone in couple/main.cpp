#include <bits/stdc++.h>
#define ll long long int


using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll x = 0,n;cin>>n;
        for(ll i=0;i<n;i++)
        {
            ll tmp; cin>>tmp;
            x = x^tmp;
        }
        cout<<x<<endl;
    }
    return 0;
}
