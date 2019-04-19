#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n; cin>>n;
	string s; cin>>s;
	ll mn = INT_MAX;
	for(ll i=0;i<=n-4;i++)
    {
        ll a = fabs('A'-s[i]) , b = fabs('C'-s[i+1]) , c = fabs('T'-s[i+2]) ,d =fabs('G'-s[i+3]);
        if(a>26-a+1)
        {
            a = 26 -a;
        }
        if(b>26-b+1)
        {
             b= 26 -b;
        }
        if(c>26-c+1)
        {
            c = 26 -c;
        }
        if(d>26-d+1)
        {
            d = 26 -d;
        }
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if(mn>a+b+c+d)
            mn=a+b+c+d;
    }
    cout<<mn<<endl;
	return 0;
}
