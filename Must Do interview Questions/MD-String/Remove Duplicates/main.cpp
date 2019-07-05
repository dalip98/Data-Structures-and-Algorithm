#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    cin.ignore();
    while(t--)
    {

        string s;
        getline(cin ,s);
        vector<ll>arr(256,0);

        for(ll i=0;i<s.size();i++)
        {

            if(!arr[s[i]])
            {
                cout<<s[i];
                arr[s[i]] = 1;
            }
        }
        cout<<endl;
    }
    return 0;
}
