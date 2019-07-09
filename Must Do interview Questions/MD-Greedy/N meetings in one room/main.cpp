#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<pair<ll,ll>>arr(n),brr(n);
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i].second;
        }

        for(ll i=0;i<n;i++)
        {
            cin>>arr[i].first;
            brr[i].first = arr[i].first;
            brr[i].second = i;
        }
        sort(brr.begin() ,brr.end());

        sort(arr.begin(),arr.end());

        ll fin = arr[0].first,cnt =1;

        //cout<<brr[0].second+1<<" ";

        for(ll i=1;i<n;i++)
        {
            if(arr[i].second>=fin)
            {
                fin = arr[i].first;
                //cout<<brr[i].second+1<<" ";
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
