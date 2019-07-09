#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        stack<char>c;
        ll n = s.size(),flag = 0;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' ||s[i]=='[')
                c.push(s[i]);
            else
            {
                if(s[i]==')')
                {
                    if(c.empty())
                    {
                        cout<<"not balanced"<<endl;
                        flag = 1;
                        break;
                    }
                    if(c.top()!='(')
                    {
                        cout<<"not balanced"<<endl;
                        flag = 1;
                        break;
                    }
                    else
                        c.pop();

                }

                if(s[i]=='}')
                {
                    if(c.empty())
                    {
                        cout<<"not balanced"<<endl;
                        flag = 1;
                        break;
                    }
                    if(c.top()!='{')
                    {
                        cout<<"not balanced"<<endl;
                        flag = 1;
                        break;
                    }
                    else
                        c.pop();

                }

                if(s[i]==']')
                {
                    if(c.empty())
                    {
                        cout<<"not balanced"<<endl;
                        flag = 1;
                        break;
                    }
                    if(c.top()!='[')
                    {
                        cout<<"not balanced"<<endl;
                        flag = 1;
                        break;
                    }
                    else
                        c.pop();

                }


            }

        }
        if(flag==1)
            continue;
        if(!c.empty())
        {
            cout<<"not balanced"<<endl;
        }
        else
        {
            if(flag==1)
                continue;
            else
            {
                cout<<"balanced"<<endl;
            }
        }
    }
    return 0;
}
