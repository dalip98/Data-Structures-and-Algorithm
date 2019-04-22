#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	string s; cin>>s;
	ll n= s.size(),cnt = 0,z=0;
	string t ;
	for(ll i=0;i<n;i++)
    {
        if(s[i]!='a')
            t+=s[i];
        else
            cnt=i ,z++;
    }
    ll l =t.size();
    for(ll i=0;i<l/2;i++)
    {
        if(t[i]!=t[l/2+i])
        {
            cout<<":("<<endl;
            return 0;
        }
    }
    //cout<<cnt<<" "<<z<<endl;
    ll r = n- cnt - 1;
    ll m = cnt + 1 - z ;
    if(r<m||l%2)
    {
        cout<<":("<<endl;
        return 0;
    }
    for(ll i=0;i<n-l/2;i++)
        cout<<s[i];
	return 0;
}
