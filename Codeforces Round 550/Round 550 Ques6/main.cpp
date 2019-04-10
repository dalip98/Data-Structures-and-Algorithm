#include <bits/stdc++.h>
#include<algorithm>
#include<vector>
#define ll long long int
#define mod 1000000007


using namespace std;

const ll N = 200000 + 11;

ll n , m;
vector<ll>g[N];
vector<pair<ll,ll> >e;
bool bipartite ;
vector<ll>color;
void dfs(ll v ,ll c)
{
    color[v] = c;
    for(auto to: g[v])
    {
        if(color[to]==-1)
            dfs(to , c^1);
        else
        {
            if(color[v]==color[to])
            {
                bipartite = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll x,y; cin>>x>>y;
        --x,--y;
        g[x].push_back(y);
        g[y].push_back(x);
        e.push_back(make_pair(x,y));
    }
    bipartite = true;
    color = vector<ll>(n , -1);
    dfs(0,0);
    if(!bipartite)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(ll i=0;i<m;i++)
    {
        cout<<(color[e[i].first]<color[e[i].second]);
    }
    cout<<endl;
    return 0;
}
