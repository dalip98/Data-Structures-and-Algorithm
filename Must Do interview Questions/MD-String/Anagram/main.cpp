#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        vector<ll>arr(26);
        ll len = s.size();
        for(ll i=0;i<len;i++)
        {
            arr[s[i]-'a']++;
        }
        cin>>s;
        len =s.size();
        for(ll i=0;i<len;i++)
        {
            arr[s[i]-'a']--;
        }
        ll flag =0;
        for(ll i=0;i<26;i++)
        {
            if(arr[i]!=0)
                flag=1;
        }
        if(flag==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}
