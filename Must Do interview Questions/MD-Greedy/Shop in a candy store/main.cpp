#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,k; cin>>n>>k;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        ll sum=0,x=n;
        for(ll i=0;i<x;i++)
        {
            sum+=arr[i];
            x-=k;
        }
        cout<<sum<<" ";
        sum=0,x=0;
        for(ll i=n-1;i>=x;i--)
        {
            sum+=arr[i];
            x+=k;

        }
        cout<<sum<<endl;
    }
    return 0;
}
