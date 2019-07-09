#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        stack<ll>s;
        for(ll i=0;i<n;i++)
        {
        if(s.empty()){
                s.push(i);
                continue;
        }
                while((arr[s.top()]<arr[i]))
                {
                    arr[s.top()] = arr[i];
                    s.pop();
                    if(s.empty())
                        break;
                }
                s.push(i);
        }
        while(!s.empty())
        {
            arr[s.top()] = -1;
            s.pop();
        }

        for(auto x:arr)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
