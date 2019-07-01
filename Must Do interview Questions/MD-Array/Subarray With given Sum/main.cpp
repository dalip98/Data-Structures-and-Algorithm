#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll subarray(vector<ll>arr , ll n ,ll sum)
{
    ll s = arr[0] ,curr = 0;

    for(ll i=1;i<=n;i++)
    {
        while(s>sum&&curr<i-1)
        {
            s-=arr[curr];
            curr++;
        }
        if(s==sum)
        {
            cout<<curr+1<<" "<<i<<endl;
            return 1;
        }
        s+=arr[i];
    }
    return 0;

}

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll sum; cin>>sum;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        if(!subarray(arr , n ,sum))
            cout<<-1<<endl;
    }
    return 0;
}
