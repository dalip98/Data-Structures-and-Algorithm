// CPP code for printing shortest path between
// two vertices of unweighted graph
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;

// utility function to form edge between two vertices
// source and dest
void add_Edge(list<ll> adj[], ll src, ll dest)
{
	adj[src].push_back(dest);
}

void delEdge(list<ll> adj[] , ll src ,ll dest)
{
    adj[src].remove(dest);
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool BFS(list<ll> adj[], ll src, ll dest, ll v,
							ll pred[], ll dist[])
{
	// a queue to maintain queue of vertices whose
	// adjacency list is to be scanned as per normal
	// DFS algorithm
	list<ll> queu;

	// boolean array visited[] which stores the
	// information whether ith vertex is reached
	// at least once in the Breadth first search
	bool visited[v];

	// initially all vertices are unvisited
	// so v[i] for all i is false
	// and as no path is yet constructed
	// dist[i] for all i set to infinity
	for (ll i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = v+1;
		pred[i] = -1;
	}

	// now source is first to be visited and
	// distance from source to itself should be 0
	visited[src] = true;
	dist[src] = 0;
	queu.push_back(src);

	// standard BFS algorithm
	while (!queu.empty()) {
		ll u = queu.front();
		queu.pop_front();
		list<ll>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); i++) {
			if (visited[*i] == false) {
				visited[*i] = true;
				dist[*i] = dist[u] + 1;
				pred[*i] = u;
				queu.push_back(*i);
				// We stop BFS when we find
				// destination.
				if (*i == dest)
				return true;
			}
		}
	}

	return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void printShortestDistance(list<ll> adj[], ll s, ll dest, ll v)
{
	// predecessor[i] array stores predecessor of
	// i and distance array stores distance of i
	// from s
	ll pred[v], dist[v];


	if (BFS(adj, s, dest, v, pred, dist) == false)
	{
		return;
	}
	vector<ll> path;
	// vector path stores the shortest path

	ll crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}

	// distance from source is in distance array
	ll len = path.size();
	for (ll i =len - 1; i >= 1; i--)
		{
		    if(path[i-1]-path[i]!=1)
                cout<<"S";
            else
                cout<<"E";
		}
		cout<<endl;
}

// Driver program to test above functions
int main()
{

	ll t; cin>>t;
	ll z =t;
	while(t--)
    {
    ll n; cin>>n;
	ll v = n*n;
	string s; cin>>s;

	list<ll> adj[v];

        for(ll i=0 ; i<n*n-1; i++)
        {
            if((i+1)%n==0)
                continue;
            else
                add_Edge(adj,i , i+1);
        }
        for(ll i=0;i<n*n-n;i++)
        {
            add_Edge(adj , i , i+n );
        }
        ll len =s.size();
        ll temp = 0;
        for(ll i=0;i<len;i++)
        {
            if(s[i]=='E')
            {
                delEdge(adj , temp , temp+1);
                temp++;
            }
            else
            {
                delEdge(adj , temp , temp+n);
                temp+=n;
            }
        }

	ll source = 0, dest = n*n - 1;
	cout<<"Case #"<<z-t<<": ";
	printShortestDistance(adj, source, dest, v);
    }
	return 0;
}
