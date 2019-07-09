#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,s; cin>>n>>s;
        if(s==0&&n!=1)
        {
            cout<<-1<<endl;
            continue;
        }
        vector<ll>arr(n);
        if(n*9<s)
        {
            cout<<-1<<endl;
            continue;
        }
        for(ll i=0;i<n;i++)
        {
            if(s==0)
                break;
            if(s>=9)
            {
                arr[i]=9;
                s-=9;
            }
            else
            {
                arr[i] = s;
                s=0;
            }
        }
        for(auto x:arr)
            cout<<x;
        cout<<endl;
    }
    return 0;
}
