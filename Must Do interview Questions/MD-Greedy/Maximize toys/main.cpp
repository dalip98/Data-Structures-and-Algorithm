#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--){
    ll n,k; cin>>n>>k;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll sum=0;
    sort(arr.begin(),arr.end());
    for(ll i=0;i<n;i++)
    {
        if(k>=arr[i])
        {
            k-=arr[i];
            sum++;
        }
        else
            break;
    }
    cout<<sum<<endl;
    }
    return 0;
}
