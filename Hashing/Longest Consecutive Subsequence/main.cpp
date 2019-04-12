#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ll n; cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    unordered_set<ll>mp;
    for(ll i=0;i<n;i++)
        mp.insert(arr[i]);
    ll ans = 0;
    for(ll i=0;i<n;i++)
    {
        if(mp.find(arr[i]-1)==mp.end())
        {
            ll j = arr[i];
            while(mp.find(j)!=mp.end())
                j++;
            ans = max(ans , j-arr[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
