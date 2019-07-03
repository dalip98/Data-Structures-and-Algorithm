#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll m,n; cin>>m>>n;
        vector<ll>arr(m),brr(n);
        for(ll i=0;i<m;i++)
            cin>>arr[i];

        for(ll i=0;i<n;i++)
            cin>>brr[i];
        ll sum = 0;
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(brr[j]*log(arr[i])>arr[i]*log(brr[j]))
                    sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
