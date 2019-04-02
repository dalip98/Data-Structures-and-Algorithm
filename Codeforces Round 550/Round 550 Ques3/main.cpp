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
    ll m =0 , temp=0;
    for(ll i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            temp++;
            m = max( m ,temp);
        }
        else
            temp = 0;
    }
    if(m>1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;



        if(n%2!=0)
            cout<<n/2+1<<endl;
        else
            cout<<n/2<<endl;

        for(ll i=0;(i<n);i++)
        {
            if(i%2==0)
                cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<n/2<<endl;

        for(ll i=n-1;(i>=0);i--)
        {
            if(i%2!=0)
                cout<<arr[i]<<" ";
        }
    }
    return 0;
}
