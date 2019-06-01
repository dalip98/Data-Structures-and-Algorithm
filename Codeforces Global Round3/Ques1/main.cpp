#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll a,b,c; cin>>a>>b>>c;
	ll sum=0;
	if(a>b)
    {
        sum+=b;
        if(a>=b+1)
        {
            sum+=(b+1);
        }
        else
            sum+=a;
        sum+=2*c;
    }
    else
    {
        sum+=a;
        if(b>=(a+1))
        {
            sum+=(a+1);
        }
        else
            sum+=b;
        sum+=2*c;
    }

    cout<<sum<<endl;
	return 0;
}
