#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to find gcd of array of
// numbers
ll findGCD(ll arr[], ll n)
{
    ll result = arr[0];
    for (ll i = 1; i < n; i++)
        result = gcd(arr[i], result);

    return result;
}

int main()
{
	ios::sync_with_stdio(0);
	ll n,m; cin>>n>>m;
	ll arr[n];
	for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll crr[n-1];
    for(ll i=1;i<n;i++)
    {
        crr[i-1]=arr[i]-arr[0];
    }
    ll brr[m];
    for(ll i=0;i<m;i++)
        cin>>brr[i];
    ll x= findGCD(crr , n-1);
    //cout<<x<<endl;
    ll temp=-1;
    for(ll i=0;i<m;i++)
    {
        if(x%brr[i]==0)
        {
            temp = i;
        }
    }
    if(temp!=-1)
    {
        cout<<"YES"<<endl;
        cout<<arr[0]<<" "<<temp+1<<endl;
    }
    else
        cout<<"NO"<<endl;
	return 0;
}
