#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,k; cin>>n>>k;
        ll x = pow(2,k);
        cout<<(n|x)<<endl;
    }
    return 0;
}
