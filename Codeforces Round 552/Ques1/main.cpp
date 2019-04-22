#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    vector<ll>arr(4);
    ll sum = 0 , j;
    for(ll i=0;i<4;i++)
        {cin>>arr[i];sum += arr[i];}
    for(ll i=0;i<4;i++)
    {
        if(arr[i]==sum/3)
            j=i;
    }
    for(ll i=0;i<4;i++)
    {
        if(i!=j)
        {
            cout<<sum/3 - arr[i]<<" ";
        }
    }
    return 0;
}
