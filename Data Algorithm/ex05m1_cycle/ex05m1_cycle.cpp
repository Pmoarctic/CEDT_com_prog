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

void DFS(int &src,vector<vi> &adj,vector<bool> &vis,int prev,int cur,bool &res)
{
    if(res==0)return;
    if(vis[cur]==1)
    {
        res = 0;
        return;
    }
    else
    {
        vis[cur] = 1;
        for(auto i:adj[cur])
        {
            if(i==prev)continue;
            DFS(src,adj,vis,cur,i,res);
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,e;
        cin >> n >> e;
////////////////////////contruct
        vector<vi> adj(n);
        vector<bool> vis(n,false);
        while(e--)
        {
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
////////////////////////////////////
//DFS
        bool res=1;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                DFS(i,adj,vis,-1,i,res);
            }
            if(res == 0)
            {
                break;
            }
        }

        if(res == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
//
    }



    return 0;
}