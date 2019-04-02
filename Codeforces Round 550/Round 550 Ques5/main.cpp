#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ll k; cin>>k;
    string s ,t; cin>>s>>t;
    vector<ll>arr(k+1) , brr(k+1);
    for(ll i=0;i<k;i++)
    {
        arr[i+1] = s[i] - 'a';
        brr[i+1]= t[i] - 'a';
    }

    for(ll i=k ; i>=0; i--)
    {
        arr[i]+=brr[i];
        if(i>0)
        {
             arr[i-1]+=arr[i]/26;
             arr[i]= arr[i]%26;
        }
    }

    for(ll i=0;i<=k;i++)
    {
        ll rem = arr[i]%2;
        arr[i]/=2;
        if(i+1<=k)
        {
            arr[i+1]+=rem*26;
        }
        else
            rem = 0;
    }

    for(ll i=1;i<=k;i++)
        cout<<char('a'+arr[i]);
    cout<<endl;


    return 0;
}
