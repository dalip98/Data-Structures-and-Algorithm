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
	ll cnt = 0;
	ll l =s.size();
	for(ll i=0;i<l;i++)
    {
        if(s[i]=='a')
            cnt++;
    }
    while(l>cnt)
    {
        if(cnt>l/2)
            {cout<<l<<endl;return 0;}
        else
            l--;
    }
    cout<<cnt<<endl;
	return 0;
}

