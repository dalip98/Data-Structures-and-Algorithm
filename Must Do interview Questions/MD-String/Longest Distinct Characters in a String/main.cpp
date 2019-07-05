#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        ll n = s.size();
        vector<ll>arr(26 , -1);
        ll mx = 0,tmp = 0;
        for(ll i=0;i<n;i++)
        {
            if(arr[s[i]-'a']==-1)
            {
                tmp++;
            }
            else
            {
                if(arr[s[i]-'a']>= i -tmp)
                {
                    tmp = i - arr[s[i]-'a'];
                }
                else
                    tmp++;

            }
            mx = max(mx ,tmp);
            arr[s[i]-'a'] = i;

        }
        cout<<mx<<endl;

    }
    return 0;
}
