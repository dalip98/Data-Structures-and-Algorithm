#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll kadane(vector<ll>arr ,  ll n)
{
    ll sum = 0,mx = INT_MIN;
    for(ll i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>mx)
        {
            //sum+=arr[i];
            mx = sum;
        }
        if(sum<0)
            sum = 0;
    }
    return mx;
}

int main()
{
    ll t;cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        cout<<kadane(arr ,n)<<endl;
    }
    return 0;
}
