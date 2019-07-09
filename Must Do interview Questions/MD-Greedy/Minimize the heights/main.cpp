#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll k; cin>>k;
        ll n; cin>>n;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        ll x = n/2+n%2;

        for(ll i=0;i<n;i++)
        {
            if(i==x)
                continue;
            else
            {
                if(arr[x]>arr[i])
                {
                    if(fabs(arr[x]-arr[i])>fabs(arr[i]+k-arr[x]))
                    {
                        arr[i]+=k;
                    }
                }
                else if(arr[x]<arr[i])
                {
                    if(fabs(arr[x]-arr[i])>fabs(arr[i]-k-arr[x]))
                    {
                        arr[i]-=k;
                    }
                }
            }
        }
        sort(arr.begin(),arr.end());
        cout<<arr[n-1]-arr[0]<<endl;
    }
    return 0;
}
