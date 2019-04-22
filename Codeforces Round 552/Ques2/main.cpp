#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ll n; cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin() , arr.end());

    vector<ll>brr;
    brr.push_back(arr[0]);
    for(ll i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
            continue;
        else
            brr.push_back(arr[i]);
    }
    ll l = brr.size();
    if(l>3)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        if(l==1)
        {
            cout<<0<<endl;
            return 0;
        }
        if(l==2)
        {
            if((brr[1]-brr[0])%2)
            {
                cout<<brr[1]-brr[0]<<endl;
            }
            else
                cout<<(brr[1]-brr[0])/2<<endl;

        }
        else
        {
            if(brr[2]-brr[1]==brr[1]-brr[0])
            {
                cout<<brr[1]-brr[0]<<endl;
            }
            else
                cout<<-1<<endl;
        }
    }
    return 0;
}
