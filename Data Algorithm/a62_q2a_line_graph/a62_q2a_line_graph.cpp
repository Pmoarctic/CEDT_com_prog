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

set<int> adj[100005];
vector<bool> vis(100005,0);
void dfs(int cur,bool &isline)
{
    if(vis[cur]==1)
    {
        return;
    }
    else
    {
        //cout << cur << " ";
        vis[cur]=1;
        if(adj[cur].size() > 2)
        {
            isline = 0;
        }
        for(auto i:adj[cur])
        {
            dfs(i,isline);
        }
        return;
    }
}

int main()
{
    int v,e;
    cin >> v >> e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int res=0;
    for(int i=0;i<v;i++)
    {
        
        if(vis[i]==0)
        {   
            bool fg=1;
            dfs(i,fg);
            //cout << "\n";
            if(fg)res++;
        }
        
    }

    cout << res;

    return 0;
}