#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007

#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
#define LOOK_UP P6(0), P6(1), P6(1), P6(0)



using namespace std;


unsigned ll table[256] = { LOOK_UP };

// Function to find the parity
ll Parity(ll num)
{
    // Number is considered to be of 32 bits
    ll mx = 16;

    // Dividing the number into 8-bit
    // chunks while performing X-OR
    while (mx >= 8) {
        num = num ^ (num >> mx);
        mx = mx / 2;
    }

    // Masking the number with 0xff (11111111)
    // to produce valid 8-bit result
    return table[num & 0xff];
}

int main()
{
    ios::sync_with_stdio(0);
    ll n; cin>>n;
    vector<ll>arr(n);
    vector<ll>od;
    vector<ll>ev;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%2!=0)
        {
            od.push_back(arr[i]);
        }
        else
            ev.push_back(arr[i]);
    }

    sort(od.begin() , od.end());
    sort(ev.begin() , ev.end());

    ll  lod = od.size() , lev = ev.size();
//cout<<lod<<" "<<lev<<endl;
    if(fabs(lod-lev)<=1)
    {
        cout<<0<<endl;
        return 0;
    }
    ll sum = 0 , temp = 0;
    if(lod>lev)
    {

        for(ll i=0;i<lod-lev-1 ; i++)
            sum+=od[i];
        cout<<sum<<endl;
    }
    else
    {
        for(ll i=0;i<lev-lod-1 ; i++)
            temp+=ev[i];
        cout<<temp<<endl;
    }

    return 0;
}
