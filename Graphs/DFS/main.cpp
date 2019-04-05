#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

class Graph{
    ll v;
    list<ll> *adj;
    void help(ll v , bool visited[]);
public:
    Graph(ll v);

    void addEdge(ll v ,ll w);

    void DFS(ll source);
};

Graph::Graph(ll v)
{
    this->v = v;
    adj = new list<ll>[v];
}

void Graph::addEdge(ll v, ll w)
{
    adj[v].push_back(w);
}

void Graph::help(ll v , bool visited[])
{
    visited[v] = true;
    cout<<v<<" ";

    list<ll>::iterator i;

    for(i = adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
        {
            help(*i , visited);
        }
    }
}

void Graph::DFS(ll v)
{
    bool *visited = new bool[v];
    for(ll i=0;i<v;i++)
        visited[i] = false;
    help(v,visited);
}

int main()
{
    ios::sync_with_stdio(0);

    Graph grph(4);
    grph.addEdge(0, 1);
    grph.addEdge(0, 2);
    grph.addEdge(1, 2);
    grph.addEdge(2, 0);
    grph.addEdge(2, 3);
    grph.addEdge(3, 3);

    grph.DFS(2);
    return 0;
}
