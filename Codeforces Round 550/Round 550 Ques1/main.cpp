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
    while(t--){
    string s; cin>>s;
    ll flag = 0 , n =s.size();
    vector<ll>arr(26);
    for(ll i=0;i<n;i++)
    {
        arr[s[i]-'a']++;
    }
    ll z =arr[0] , sum=0;
    for(ll i=0;i<26;i++)
    {
        if(z!=arr[i])
        {
            sum++;
            z=arr[i];
        }
        if(arr[i]>1)
            flag=1;
    }
    if(flag==1)
        cout<<"No"<<endl;
    else
    {
            if(sum<=2)
            {
                if(arr[0]==1)
                {
                    if(sum<=1)
                        cout<<"Yes"<<endl;
                    else
                        cout<<"No"<<endl;
                }

                else
                    cout<<"Yes"<<endl;
            }
            else
                cout<<"No"<<endl;
    }
    }
    return 0;
}
