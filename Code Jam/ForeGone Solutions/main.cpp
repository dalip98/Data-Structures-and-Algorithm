#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ll t; cin>>t;
    ll z = t;
    while(t--)
    {
        string s; cin>>s;
        vector<ll>arr;
        ll l = s.size(),temp=1;
        for(ll i=l-1;i>=0;i--)
        {
            arr.push_back(s[i]-'0');
        }


        ll len = arr.size();
        vector<ll>brr(len);
        for(ll i=0;i<len;i++)
        {
            if(arr[i]==8)
            {
                arr[i]=5;
                brr[i]=3;
            }
            else if(arr[i]==9)
            {
                arr[i]=6;
                brr[i]=3;
            }
            else if(arr[i]==7)
            {
                arr[i]=5;
                brr[i]=2;
            }
            else
            {
                brr[i]=arr[i]/2;
                arr[i]=arr[i]-brr[i];
            }
        }
        ll x=0,y=0,p=1;
        for(ll i=0;i<len;i++)
        {
            x+=(arr[i]*p);
            y+=(brr[i]*p);
            p*=10;
        }
        cout<<"Case #"<<z-t<<" ";
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
