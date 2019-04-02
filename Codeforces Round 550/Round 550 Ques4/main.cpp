#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ll n ; cin>>n;
    vector<ll>arr(n) , cnt(200001);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    ll mx = max_element(cnt.begin() , cnt.end()) - cnt.begin();
    ll pos = find(arr.begin(),arr.end() , mx) - arr.begin();

    //cout<<mx<<" "<<pos<<endl;

    cout<<n-cnt[mx]<<endl;

    for(ll i=pos-1;i>=0;i--)
    {
        cout<<1 + (arr[i]>arr[i+1])<<" "<<i+1<<" "<<i+2<<endl;
        arr[i] = arr[i+1];
    }

    for(ll i = pos ; i<n-1;i++)
    {
        if(arr[i+1]!=mx)
        {
            cout<<1 + (arr[i+1]>arr[i])<<" "<<i+2<<" "<<i+1<<endl;
            arr[i+1]=arr[i];
        }
    }

    return 0;
}
