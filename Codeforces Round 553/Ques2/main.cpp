#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n,m; cin>>n>>m;
	ll sum = 0 , rw =0 , cl =0,xr;
	for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            ll a; cin>>a;
            if(j==1)
            {
                xr = a;
            }
            else if(xr!=a)
            {
                rw = i , cl = j;
            }
        }
        sum^=xr;
    }
    if(sum!=0||rw!=0)
    {
        cout<<"TAK\n";
        for(ll i=1;i<=n;i++)
        {
            cout<<((sum==0&&i==rw)?cl:1)<<" ";

        }
        cout<<endl;
        return 0;
    }
    cout<<"NIE\n";
	return 0;
}
