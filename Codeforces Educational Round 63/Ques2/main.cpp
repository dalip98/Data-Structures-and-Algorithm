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
	ll sum=0;
	for(ll i=0;i<n;i++)
    {
        if(s[i]=='8')
            sum++;
    }
    ll mv = (n-11)/2;
    if(mv >=sum)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else
    {
        ll temp=0,k;
        for(ll i=0;i<n;i++)
        {

            if(s[i]=='8')
                temp++;
            if(temp == mv+1)
            {
                k=i;
                break;
            }
        }
        k++;
        //cout<<k<<endl;
        if(k <= 2*mv+1)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;

    }
	return 0;
}
