#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ll t; cin>>t;
    while(t--)
    {
        ll n,k ; cin>>n>>k;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        unordered_map<ll ,ll>cnt;
        for(ll i=0;i<n;i++)
            cnt[arr[i]]++;
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            sum+=cnt[k-arr[i]];
            if(k-arr[i] == arr[i])
                sum--;
        }
        cout<<sum/2<<endl;
    }
    return 0;
}
