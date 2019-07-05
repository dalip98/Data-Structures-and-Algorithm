#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void ComputeLPSArray(string b,ll m ,ll* lps);

void KMPSearch(string b , string a)
{
    ll m  = b.size();
    ll n = a.size();

    ll lps[m];
    ComputeLPSArray(b,m,lps);
    ll i=0,j=0;
    while(i<n)
    {
        if(b[j]==a[i])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            cout<<i-j<<endl;
            return;
        }
        else if(i<n&&b[j]!=a[i])
        {
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
    cout<<-1<<endl;
}

void ComputeLPSArray(string b,ll m ,ll* lps)
{
    ll len = 0;
    lps[0]=0;
    ll k =1;
    while(k<m)
    {
        if(b[k]==b[len])
        {
            len++;
            lps[k]=len;
            k++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i]=0;
                k++;
            }
        }
    }
}

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        string a ,b; cin>>a>>b;
        KMPSearch(b,a);
    }
    return 0;
}
