#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n ; cin>>n;
	string s; cin>>s;
	vector<ll >arr(n);
	for(ll i=0;i<n;i++)
    {
        arr[i] = s[i];
    }
    ll mx = arr[0] , j=0;
    for(ll i=1;i<n;i++)
    {
        if(arr[i]>=mx)
        {
            mx = arr[i];
            j=i;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<j+1<<" "<<i+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;

	return 0;
}
