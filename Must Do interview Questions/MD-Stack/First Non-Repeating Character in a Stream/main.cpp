#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<char>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        queue<char>q;
        vector<ll>crr(26);
        for(ll i=0;i<n;i++)
        {
            q.push(arr[i]);
            crr[arr[i]-'a']++;
            ll flag = 0;
            while(!q.empty())
            {
                if(crr[q.front()-'a']==1)
                {
                    cout<<q.front()<<" ";
                    flag = 1;
                    break;
                }
                else
                {
                    q.pop();
                }
            }
            if(flag==0)
            {
                cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
