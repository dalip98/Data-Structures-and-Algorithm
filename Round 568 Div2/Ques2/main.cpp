#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	ll t; cin>>t;
	while(t--)
    {
        string a; cin>>a;
        string b; cin>>b;
        ll x =a.size() , y =b.size(),flag = 0;
        if(x>y)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            ll c = 0 , p=c-1;

            for(ll i=0;i<y;)
            {
                p=c-1;
                if(b[i] == a[c])
                {
                    i++;
                    c++;
                }
                else
                {
                    if(p<0)
                    {
                        //cout<<"NO"<<endl;
                        flag=1;
                        break;
                    }
                    else
                    {
                        if(b[i]==a[p])
                            i++;
                        else
                        {
                            flag=1;
                            break;
                        }
                    }
                }
            }
            if(flag==1||c<x)
            {
                cout<<"NO"<<endl;
            }
            else
                cout<<"YES"<<endl;
        }
    }
	return 0;
}
