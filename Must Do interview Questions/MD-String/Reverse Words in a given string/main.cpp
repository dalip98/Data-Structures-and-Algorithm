#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        string s; cin>>s;

        ll d = 0;
        for(ll i=0;i<s.size();i++)
        {
            if(s[i]=='.')
                d++;
        }
        stack<char>q;
        for(ll i=s.size()-1;i>=0;i--)
        {
            if(s[i]!='.')
            {
                q.push(s[i]);
            }
            else
            {
                while(!q.empty())
                {
                    cout<<q.top();
                    q.pop();
                }
                if(d!=0)
                {
                    cout<<".";
                    d--;
                }
            }
        }
        while(!q.empty())
                {
                    cout<<q.top();
                    q.pop();
                }
            cout<<endl;
    }
    return 0;
}
