#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void permute(string s,ll l,ll r)
{
    if(l==r)
        cout<<s<<" ";
    else
    {
        for(ll i=l;i<=r;i++)
        {
            swap(s[l] , s[i]);
            permute(s , l+1 , r);
            swap(s[i] , s[l]);
        }
    }
}

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        permute(s ,0 , s.size()-1);
        cout<<endl;
    }
    return 0;
}
