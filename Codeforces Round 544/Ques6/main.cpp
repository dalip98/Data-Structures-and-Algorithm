#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll long long int
#define mod 1000000007

using namespace std;



mt19937 rnd(time(NULL));

ll n,m;

vector<vector<ll>>g;
vector<ll>deg;
vector<pair<ll,ll> >ans;

void bfs(ll s)
{
    vector<ll>used(n);
    used[s]=1;
    queue<ll>q;
    q.push(s);

    while(!q.empty())
    {
        ll v= q.front();
        q.pop();
        for(auto to:g[v])
        {
            if(used[to])
                continue;
            if(rnd()&1)
                ans.push_back(make_pair(v,to));
            else
                ans.push_back(make_pair(to ,v));
            used[to]=1;
            q.push(to);

        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	 cin>>n>>m;
	 g = vector<vector<ll>>(n);
	 deg = vector<ll>(n);
	for(ll i=0;i<m;++i)
    {
        ll x,y; cin>>x>>y;
        --x;--y;
        g[x].push_back(y);
        g[y].push_back(x);
        ++deg[x];
        ++deg[y];
    }
    ll pos = 0;
    for(ll i=0;i<n;i++)
    {
        if(deg[pos]<deg[i])
            pos=i;
    }
    bfs(pos);

    for(auto it:ans)
    {
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }
	return 0;
}
