#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void printe(vector<ll>arr , ll n)
{
    ll mn = 0 ,mx =0 ,e =arr[0];
    queue<pair<ll,ll>>ans;
    for(ll i=1;i<n;i++)
    {
        if(arr[i]>=e)
        {
            if(i==n-1)
            {
                mx++;
                ans.push(make_pair(mn ,mx));
            }
            mx++;
        }
        else
        {
            ans.push(make_pair(mn ,mx));
            mn=i;
            mx=i;

        }
        e = arr[i];
        //cout<<mn<<" "<<mx<<endl;
    }
    ll flag=0;
    while(!ans.empty())
    {
        if(ans.front().first!=ans.front().second)
        {
            cout<<"("<<ans.front().first<<" "<<ans.front().second<<") ";
            flag=1;
        }

        ans.pop();

    }
    if(flag==0)
    {
        cout<<"No Profit";
    }
}

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        printe(arr ,n);
        cout<<endl;
    }
    return 0;
}
