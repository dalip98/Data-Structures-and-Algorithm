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
        ll sum=-1;
        stack<ll>q;
        for(ll i = n-1;i>=0;i--)
        {
            if(arr[i]>=sum)
            {
                q.push(arr[i]);
                sum = arr[i];
            }
        }
        while(!q.empty())
        {
            cout<<q.top()<<" ";
            q.pop();
        }
        cout<<endl;
    }
    return 0;
}
