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
        string s; cin>>s;
        vector<ll>arr(n),crr(n);
        for(ll i=n-1;i>=0;i--)
        {
            //cin>>arr[i];
            arr[i] = s[i]-'0';

            crr[i]=arr[i];
        }
        vector<ll>brr(10);
        for(ll i=1;i<10;i++)
            cin>>brr[i];
        for(ll i=0;i<n;i++)
        {
            crr[i]-=brr[crr[i]];
        }
        ll pos = -1;
        for(ll i=0;i<n;i++)
        {
            if(crr[i]<0)
            {
                pos = i;
                break;
            }
        }
        if(pos==-1)
        {
            for(auto x:arr)
                cout<<x;
        }
        else
        {
            ll t;
            for(ll i=0;i<pos;i++)
                cout<<arr[i];
            for(ll i=pos;i<n;i++)
            {
                if(crr[i]<=0)
                {
                    arr[i] = brr[arr[i]];
                    cout<<arr[i];
                }
                else
                {
                    t=i;
                    break;
                }
            }
            for(ll i=t;i<n;i++)
                cout<<arr[i];
        }
        return 0;
    }
