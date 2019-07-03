#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        map<ll ,ll>arr;
        ll tmp,n; cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>tmp;
            arr.insert(make_pair(tmp ,i));
        }
        ll k,z=0; cin>>k;
        map<ll ,ll>::iterator x;
        for(x =arr.begin();x!=arr.end();x++)
        {
            z++;
            if(z==k)
            {
                 cout<<(*x).first<<endl;
            }
        }
    }
    return 0;
}
