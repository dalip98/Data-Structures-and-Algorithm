#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        string s; cin>>s;
        ll j = s.size();
        for(ll i=0;i<n-1;i++)
        {
            string tmp; cin>>tmp;
            ll k= tmp.size();
            ll l = min(j,k) ,x=0;
            for(ll i=0;i<l;i++)
            {
                if(s[i]==tmp[i])
                    x++;
            }
             j = x;
        }
        if(j==0)
        {
            cout<<-1<<endl;
            continue;
        }
        for(ll i=0;i<j;i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
