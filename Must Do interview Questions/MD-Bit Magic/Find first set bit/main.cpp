#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        ll x = pow(2,20) - 1 ,flag = 0;
        x = x&n;

        for(ll i=0;i<20;i++)
        {
            if(x&1==1)
            {
                cout<<i+1<<endl;
                flag =1;
                break;
            }
            else
                x = x>>1;
        }
        if(flag!=1)
            cout<<0<<endl;
    }
    return 0;
}
