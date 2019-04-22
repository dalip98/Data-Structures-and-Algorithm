#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ll n ,b,a; cin>>n>>b>>a;
    ll mx = a;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        if(b==0&&a==0)
            break;
        if(arr[i]==0)
        {
            if(a!=0)
                a--;
            else
                b--;
        }
        else
        {
            if(b==0)
            {
                a--;
            }
            else
            {
                if(a==mx)
                {
                    a--;
                }
                else
                {
                    b--;
                    a++;
                }
            }
        }
        //cout<<b<<" "<<a<<endl;
        sum++;
    }
    cout<<sum<<endl;

    return 0;
}
