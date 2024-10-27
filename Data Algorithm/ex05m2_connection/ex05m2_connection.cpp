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

vi adj[1200];
int dfs(int src,int k)
{
    int cnt=0;
/////////////////
    vi vis(1200,0);
    vis[src]=1;
    queue<pii> q;
    q.push({src,0});

    while(!q.empty())
    {
        auto [cur,deg] = q.front();
        q.pop();

        cnt++;
        for(auto i:adj[cur])
        {
            if(deg+1>k)
            {
                break;
            }
            if(vis[i]==0)
            {
                q.push({i,deg+1});
                vis[i]=1;
            }
        }
    }
//////////////////
    return cnt;
}

int main()
{
    int n,e,k;
    cin >> n >> e >> k;

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int res = 0;
    for(int i=0;i<n;i++)
    {        
        int cnt = dfs(i,k);
        res = max(res,cnt);
        //cout << cnt << "\n";
    }

    cout << res;

    return 0;
}

