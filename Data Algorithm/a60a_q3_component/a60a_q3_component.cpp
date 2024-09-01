#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define in(x) != x.end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

void dfs(int cur,vector<bool> &vis,vector<vi> &adj)
{
    if(vis[cur]==1)
    {
        return;
    }

    vis[cur]=1;
    for(auto i:adj[cur])
    {
        dfs(i,vis,adj);
    }
}

int main()
{
    int v,e;
    cin >> v >> e;
    vector<vi> adj(v+1);
    vector<bool> vis(v+1,false);
    
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int res=0;
    for(int i=1;i<=v;i++)
    {
        if(vis[i]==false)
        {
            res++;
            dfs(i,vis,adj);
        }
    }

    cout << res;



    return 0;
}

//counting multigraph