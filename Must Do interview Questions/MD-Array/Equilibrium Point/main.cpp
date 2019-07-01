#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,sum=0,flag = 0; cin>>n;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        ll lsum = 0;
        for(ll i=0;i<n;i++)
        {
            if(sum - lsum -arr[i] == lsum)
            {
                cout<<i+1<<endl;
                flag=1;
                break;
            }
            else
                lsum+=arr[i];
        }
        if(flag ==0)
            cout<<-1<<endl;

    }
    return 0;
}
