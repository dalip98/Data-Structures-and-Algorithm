#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        string a,b; cin>>a>>b;
        if(a.size()!=b.size())
        {
            cout<<0<<endl;
            continue;
        }
        //queue<char>q;
        ll n = a.size();
        ll flag = 0;
        for(ll i=0;i<n-2;i++)
        {
            if(a[i]!=b[i+2])
                flag=-1;
        }
        if(flag==0)
        {
            if((b[0]==a[n-2])&&(b[1]==a[n-1]))
            {
                cout<<1<<endl;
                continue;
            }
        }
        flag=0;
        for(ll i=0;i<n-2;i++)
        {
            if(a[i+2]!=b[i])
                flag=-1;
        }
        if(flag==0)
        {
            if((b[n-2]==a[0])&&(b[n-1]==a[1]))
            {
                cout<<1<<endl;
                continue;
            }
        }

        cout<<0<<endl;
    }
    return 0;
}
