#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n,k; cin>>n>>k;
        deque<ll>q,q1;
        for(ll i=0;i<16;i++)
        {
            ll y = pow(2,i);
            if(y&n)
                q.push_back(1);
            else
                q.push_back(0);
        }
        for(ll i=0;i<k;i++)
        {
            q.push_front(q.back());
            q.pop_back();
        }
        ll x =1,sum =0;
        while(!q.empty())
        {
            sum += (x*q.front());
            x*=2;
            q1.push_back(q.front());
            q.pop_front();
        }
        cout<<sum<<endl;
        for(ll i=0;i<2*k;i++)
        {
            q1.push_back(q1.front());
            q1.pop_front();
        }
        x =1 ,sum =0;
        while(!q1.empty())
        {
            sum += (x*q1.front());
            x*=2;
            q1.pop_front();
        }
        cout<<sum<<endl;
    }
    return 0;
}
