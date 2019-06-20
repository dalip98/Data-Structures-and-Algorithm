#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll n,m; cin>>n>>m;

	vector<ll>arr(n);
	for(ll i =0;i<n;i++)
        cin>>arr[i];

    ll sum = 0,x,ans= 0;
    vector<ll>t(101);

    for(ll i=0;i<n;i++)
    {
        ans = 0;
        sum+=arr[i];
        if(sum>m)
        {
            ll x = sum;
            for(ll i=100;i>=1;i--)
            {

                if(t[i]==0)
                    continue;
                //cout<<x<<endl;
                if(x-m <= 0)
                    break;

                ll tmp = (x-m)/i;
                if((x-m)%i!=0)
                    tmp++;
                if(tmp==0)
                {
                    ans++;
                    break;
                }
                else
                {
                    if(tmp<t[i])
                        ans+=tmp;
                    else
                    {
                        tmp=t[i];
                        ans+=tmp;
                    }
                }
                x=x-(tmp*i);
            }

            cout<<ans<<" ";

        }
        else
            cout<<0<<" ";
        t[arr[i]]++;
    }
	return 0;
}
