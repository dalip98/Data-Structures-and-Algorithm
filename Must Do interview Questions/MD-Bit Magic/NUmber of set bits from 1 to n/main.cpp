#include <bits/stdc++.h>
#define ll long long int


using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,sum=0; cin>>n;
        for(ll i=1;i<=10;i++)
        {
            ll x  = pow(2,i);
            ll m = n/x,c = n%x;
            sum+= (m*i);
            x/=2;

            if(c-x>0)
            {
                sum+=(c-x);
            }
            cout<<sum<<endl;
        }

    }
    return 0;
}
