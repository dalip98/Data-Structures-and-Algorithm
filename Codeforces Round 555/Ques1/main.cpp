#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n; cin>>n;
	ll temp=n;
	vector<ll>arr;
	arr.push_back(n);
	ll sum=1 ;
	while(n/10!=0)
    {
        n++;
        arr.push_back(n);
        while(n%10==0)
        {
            n/=10;
            arr.push_back(n);
        }
    }
    sort(arr.begin(),arr.end());
    ll l =arr.size();
    ll k=0 ,m=0;
    for(auto x:arr)
    {
        if(x<10)
            k++;
        if(x%10==0&&x!=temp)
            m++;
        //cout<<x<<endl;
    }
    cout<<l+9-k-m<<endl;
	return 0;
}
