#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    ll n,a,x,b,y; cin>>n>>a>>x>>b>>y;
    ll ta = a , tb =b;
    while(1)
    {

        if(ta==tb)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        if(ta==x||tb==y)
            break;
        if(ta==n)
        {
            ta=1;
        }
        else
            ta++;
        if(tb==1)
            tb=n;
        else
            tb--;

    }

    cout<<"NO"<<endl;

	return 0;
}
