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
        deque<ll>d;
        ll i;
        for(i=0;i<k;i++)
        {
            while(!d.empty() && arr[i]>=arr[d.back()])
            {
                d.pop_back();
            }
            d.push_back(i);
        }
        for(i=k;i<n;i++)
        {
            cout<<arr[d.front()]<<" ";


            while(!d.empty() && arr[i]>=arr[d.back()])
            {
                d.pop_back();
            }

            while(!d.empty() && d.front()<=i-k)
            {
                d.pop_front();
            }
            d.push_back(i);
        }
        cout<<arr[d.front()]<<endl;
    }
    return 0;
}
