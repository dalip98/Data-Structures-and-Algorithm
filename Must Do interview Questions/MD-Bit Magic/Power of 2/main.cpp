#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,sum=0,x =1; cin>>n;
        //vector<ll>arr(60);
        for(ll i=0;i<60;i++)
        {

            ll y = n&x;
            //cout<<x<<" "<<y<<endl;
            if(x==y)
            {

                sum++;

            }
            x*=2;
        }
        if(sum!=1)
        {
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;

    }
    return 0;
}
