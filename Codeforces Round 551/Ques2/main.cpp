#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    ll n,m,h; cin>>n>>m>>h;
    vector<ll>fnt(m);
    for(ll i=0;i<m;i++)
        cin>>fnt[i];
    vector<ll>side(n);
    for(ll i=0;i<n;i++)
        cin>>side[i];
    ll arr[n][m];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(arr[i][j]==0)
                cout<<0<<" ";
            else
            {
                cout<<min(fnt[j] , side[i])<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
