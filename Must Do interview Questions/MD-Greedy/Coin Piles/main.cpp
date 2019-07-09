#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,k; cin>>n>>k;
        vector<ll>arr(n),s(n+1);
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        for(ll i=0;i<n;i++)
        {
            s[i+1] = s[i]+arr[i];
        }
        ll mn = INT_MAX;
        for(ll j=0;j<n-1;j++){
        ll m = arr[j] , sum=s[j];
        for(ll i=j+1;i<n;i++)
        {
            if(!(fabs(arr[i]-m)<=k))
            {
                ll tmp=(arr[i]-m-k);

                if(tmp>arr[i])
                {
                    sum+=arr[i];
                }
                else
                    sum+=tmp;
            }
        }
        mn = min(mn,sum);
        }
        cout<<mn<<endl;
    }
    return 0;
}
