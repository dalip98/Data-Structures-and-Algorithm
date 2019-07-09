#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll>arr(n) ,brr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        for(ll i=0;i<n;i++)
            cin>>brr[i];
        sort(arr.begin(),arr.end());
        sort(brr.begin() ,brr.end(),greater<ll>());
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            sum+=(arr[i]*brr[i]);
        }
        cout<<sum<<endl;
    }
    return 0;
}
