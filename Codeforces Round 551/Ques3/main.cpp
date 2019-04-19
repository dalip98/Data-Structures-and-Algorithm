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

	ll l = 0 ,r =0;
	for(ll i=0;i<n;i++)
        s[i]=='('?l++:r++;

    l = n/2 - l;
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='?')
            s[i]=l-->0?'(':')';
    }

    l = 0 ,r =0;
    for(ll i=0;i<n;i++)
    {
        s[i]=='('?l++:l--;
        if(l<0)
            return cout<<":(\n" , 0;
        if(!l)
            r++;
    }
    if(l||r!=1)
        return cout<<":(\n" , 0;

    return cout<<s<<endl , 0;

	return 0;
}
