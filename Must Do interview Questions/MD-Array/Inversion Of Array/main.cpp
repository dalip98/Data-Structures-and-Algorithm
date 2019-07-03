#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll merge_s(vector<ll>&arr , ll l ,ll m ,ll r)
{
    ll n1 =  m - l +1;
    ll n2 = r - m;
    vector<ll>a(n1) , b(n2);
    for(ll i=0;i<n1;i++)
        a[i] = arr[l+i];
    for(ll i=0;i<n2;i++)
        b[i] = arr[m+1+i];
    ll i = 0 , j=0 ,k =l ,inv =0;

    while(i<n1&&j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            //ans++;
            inv = inv + (m-i);
        }
        k++;
    }
    while(i<n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
    return inv;

}

ll merge_sort(vector<ll>&arr , ll l ,ll r)
{
    ll inv =0;
    if(l<r)
    {
        ll m = l+(r-l)/2;
        inv = merge_sort(arr , l , m);
        inv+=merge_sort(arr , m+1,r);
        inv+=merge_s(arr , l , m ,r);
    }
    return inv;
}

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll>arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        cout<<merge_sort(arr , 0 , n-1)<<endl;
    }
    return 0;
}
