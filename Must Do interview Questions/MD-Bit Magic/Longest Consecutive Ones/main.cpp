#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,sum=0,x=1,ans =0; cin>>n;
        for(ll i=0;i<10;i++)
        {
            if(n&x)
            {

                sum++;
            }
            else
            {


                sum=0;
            }
            //cout<<ans<<" ";
            ans = max(ans,sum);
            x*=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
