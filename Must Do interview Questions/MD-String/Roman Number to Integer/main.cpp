#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        ll n=s.size();
        ll prev = 0 ,ans =0;
        map<char ,ll>m;
        m.insert(make_pair('I' , 1));
        m.insert(make_pair('X' , 10));
        m.insert(make_pair('V' , 5));
        m.insert(make_pair('L' , 50));
        m.insert(make_pair('C' , 100));
        m.insert(make_pair('D' , 500));
        m.insert(make_pair('M' , 1000));

        for(ll i=n-1;i>=0;i--)
        {
            if(prev>m[s[i]])
                ans-=m[s[i]];
            else
                ans+=m[s[i]];

            prev = m[s[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}
