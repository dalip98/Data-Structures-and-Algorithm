/*
Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j
iff either j = i + 1 or j = 3i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.
*/
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
    while(t--)
    {
        ll n,sum1=0,sum2=0,i; cin>>n;
        for(i=1;i<=n;)
        {
            if(i*3<=n)
            {
                sum1++;
                i=i*3;
            }
            else
                break;
        }
        sum1+=(n-i);

        for(i=n;i>=1;)
        {
            if(i==1)
                break;
            //cout<<i<<endl;
            ll temp = i%3;
            if(temp==0)
            {
                i=i/3;
                sum2++;
                continue;
            }
            sum2+=temp;
            i = i-temp;
        }

        cout<<min(sum1 ,sum2)<<endl;
    }
    return 0;
}
