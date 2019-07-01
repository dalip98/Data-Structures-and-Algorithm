#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll maxEle(vector<ll>arr ,ll n)
{
    ll sze = n;
    ll c = 1 ,maj = 0;
    for(ll i=1;i<sze;i++)
    {
        if(arr[maj] == arr[i])
            c++;
        else
            c--;
        if(c==0)
        {
            maj=i;
            c=1;
        }
    }
    return arr[maj];
}

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        ll ans = maxEle(arr , n );
        //cout<<ans<<endl;
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            if(arr[i]== ans)
                sum++;
        }
        if(sum >= n/2 +1)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
