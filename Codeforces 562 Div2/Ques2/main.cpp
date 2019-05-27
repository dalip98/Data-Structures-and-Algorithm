#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;


bool check(ll a ,ll x , vector<ll>arr , vector<ll>brr)
{
    ll m = arr.size();
    for(ll i=0;i<m;i++)
    {
        if(arr[i]==a||brr[i]==a)
        {
            continue;
        }
        else if(arr[i]==x||brr[i]==x)
            continue;
        else
            return false;
    }
    return true;
}

int main()
{
	ios::sync_with_stdio(0);
	ll n,m; cin>>n>>m;
	vector<ll>arr(m) , brr(m);
	for(ll i=0;i<m;i++)
        cin>>arr[i]>>brr[i];
    ll a = arr[0] , b= brr[0];
    ll x, y , flag = 0;
    for(ll i=0;i<m;i++)
    {
        if(arr[i]!=arr[0]&&brr[i]!=arr[0])
        {
            if(arr[i]!=brr[0]&&brr[i]!=brr[0])
            {
            x = arr[i];
            y = brr[i];
            flag = 1;
            break;
            }
        }
    }

    //cout<<x<<" "<<y<<endl;
    if(flag==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    flag = 0;
    ll p,q;
    for(ll i=0;i<m;i++)
    {
        if(arr[i]!=brr[0]&&brr[i]!=brr[0])
        {
            if(arr[i]!=arr[0]&&brr[i]!=arr[0])
            {
            p = arr[i];
            q = brr[i];
            flag = 1;
            break;
            }
        }
    }

    //cout<<p<<" "<<q<<endl;
    if(flag==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }

    bool ans = check(a,x,arr,brr);

    if(ans ==true)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    ans = check(a , y ,arr , brr);

    if(ans ==true)
    {
        cout<<"YES"<<endl;
        return 0;
    }

    ans = check(b, p,arr , brr);

    if(ans ==true)
    {
        cout<<"YES"<<endl;
        return 0;
    }

    ans = check(b , q ,arr , brr);

    if(ans ==true)
    {
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;

	return 0;
}
