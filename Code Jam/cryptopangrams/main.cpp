#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

// Function to print primes
vector<ll> printPrime(int n)
{
    vector<ll>arr;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
            {
                arr.push_back(i);
            }
    }
    return arr;
}

int main()
{
    ios::sync_with_stdio(0);
    ll t; cin>>t;
    ll z= t;
    while(t--)
    {
        ll n, l; cin>>n>>l;
        vector<ll>prm = printPrime(n);
        ll len = prm.size();
        sort(prm.begin(), prm.end());
        ll temp ,x,y; cin>>temp;
        vector<ll>arr,brr;
        for(ll i=0;i<len;i++)
        {
            if(temp%prm[i]==0)
            {
                arr.push_back(temp/prm[i]);
                arr.push_back(prm[i]);
                x = prm[i];
                brr.push_back(prm[i]);
                brr.push_back(temp/prm[i]);
                y = temp/prm[i];
                break;
            }
        }
        //cout<<"Arr.size():" <<arr.size()<<endl;
        for(ll i=0;i<l-1;i++)
        {
            cin>>temp;
            if(temp%x==0)
            {
                arr.push_back(temp/x);
                x = temp/x;
            }
            if(temp%y==0)
            {
                brr.push_back(temp/y);
                y = temp/y;
            }
        }
        //cout<<"Arr.size():" <<arr.size()<<endl;
        if(arr.size()!=l+1)
        {
            ll lx = arr.size();
            for(ll i=0;i<lx;i++)
                arr[i]=brr[i];
            for(ll i=lx;i<l+1;i++)
            {
                arr.push_back(brr[i]);
            }
        }
        else
        {
            ll lx = brr.size();
            for(ll i=0;i<lx;i++)
                brr[i]=arr[i];
            for(ll i=lx;i<l+1;i++)
                brr.push_back(arr[i]);
        }
        //cout<<"Arr.size():" <<arr.size()<<endl;

        //cout<<"Arr.size():"<<brr.size()<<endl;
        sort(brr.begin() , brr.end());
        for(ll i =l+1;i>=1;i--)
        {
            if(brr[i]==brr[i-1])
                brr[i]=0;
        }
        sort(brr.begin() , brr.end());
        vector<ll>crr;
        for(ll i=0;i<l+1;i++)
        {
            if(brr[i]!=0)
                crr.push_back(brr[i]);
        }

        cout<<"Case #"<<z-t<<": ";

        for(ll i=0;i<l+1;i++)
        {
            for(ll j=0;j<26;j++)
            {
                if(arr[i]==crr[j])
                {
                    char a ='A'+j;
                    cout<<a;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
