#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll unsigned long long int
#define mod 1000000007

using namespace std;

ll power(ll x, ll y)
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2)%mod;
    if (y%2 == 0)
        return (temp%mod*temp%mod)%mod;
    else
        return (x*temp%mod*temp%mod)%mod;
}

ll sum(ll n)
{
    ll row = 1 ,pro = 2;
    if(n==1)
        return 0;
    while(n>pro-1)
    {
        pro*=2;
        row++;
    }

    ll r_eve = row/2;
    ll r_odd = row - row/2;
    ll e_out ,o_out;
    if(row%2==0)
    {
        e_out = pro - 1 -n ;
        o_out =0;
    }
    else
    {
        o_out = pro - 1 -n ;
        e_out =0;
    }

    ll n_odd = (((power(4 , r_odd)-1 - 3*o_out)%mod)*((power(4 ,r_odd) - 1 - 3*o_out%mod)%mod))/9;
    ll n_eve =  (((2*(power(4 , r_eve)-1)-3*e_out%mod)%mod)*((2*(power(4 ,r_eve) - 1) - 3*e_out%mod +3)%mod))/9;
    return (n_odd%mod+n_eve%mod)%mod ;

}

int main()
{
	ios::sync_with_stdio(0);
	ll l,r; cin>>l>>r;
	cout<<(sum(r)-sum(l-1))%mod<<endl;
	return 0;
}
