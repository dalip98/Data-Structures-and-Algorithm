#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

class Graph{
    ll v;
    list<ll> *adj;
public:
    Graph(ll v);
    void addEdge(ll v,ll w);
    void delEdge(ll v ,ll w);
    void path(ll s ,ll d);

};

Graph::Graph(ll v)
{
    this->v=v;
    adj = new list<ll>[v];
}

void Graph::addEdge(ll v ,ll w)
{
    adj[v].push_back(w);
}
void Graph::delEdge(ll v ,ll w)
{
    adj[v].remove(w);
}

void Graph::path(ll s , ll d)
{

}


int main()
{
    ios::sync_with_stdio(0);
    ll t; cin>>t;
    ll z=t;
    while(t--)
    {
        ll n; cin>>n;
        string s; cin>>s;
        Graph g(n*n);
        for(ll i=0;i<n*n;i++)
        {
            if(i%(n-1)==0)
                continue;
            else
                g.addEdge(i , i+1);
        }
        for(ll i=0;i<n*n-n;i++)
        {
            g.addEdge(i , i+n );
        }
        ll len =s.size();
        ll temp = 0;
        for(ll i=0;i<len;i++)
        {
            if(s[i]=='E')
            {
                g.delEdge(temp , temp+1);
                temp++;
            }
            else
            {
                g.delEdge(temp , temp+n);
                temp+=n;
            }
        }
        g.isReachable(0 ,n*n-1);

    }
    return 0;
}
