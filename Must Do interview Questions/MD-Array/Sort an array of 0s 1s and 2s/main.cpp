#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll>arr(3);
        ll tmp;
        for(ll i=0;i<n;i++)
        {
            cin>>tmp;
            arr[tmp]++;
        }
        for(ll i=0;i<3;i++)
        {
            for(ll j=0;j<arr[i];j++)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
