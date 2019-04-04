#include <bits/stdc++.h>
#include<algorithm>
#include<iterator>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

class Graph
{
    ll v;
    list<ll> *adj;
public:
    Graph(ll v);

    void addEdge(ll v ,ll w);

    void BFS(ll source);
};

Graph::Graph(ll v)
{
    this->v = v;
    adj = new list<ll>[v];
}
void Graph::addEdge(ll v , ll w)
{
    adj[v].push_back(w);
}

void Graph::BFS(ll source)
{
    bool *visited = new bool[v];
    for(ll i=0;i<v;i++)
        visited[i] = false ;
    list<ll>queu;
    visited[source] = true ;
    queu.push_back(source);

    list<ll>::iterator i;
    while(!queu.empty())
    {
        ll s = queu.front();
        cout<<s<<" ";
        queu.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queu.push_back(*i);
            }
        }
    }
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

    grph.BFS(2);
    return 0;
}
