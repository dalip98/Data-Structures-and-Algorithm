#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,m; cin>>n>>m;
        if(n==m)
        {
            return -1;
        }
        n = n^m;
        for(ll i=0;i<10;i++)
        {
            if(n&1==1)
            {
                cout<<i+1<<endl;
                break;
            }
            n = n>>1;
        }
    }
    return 0;
}
