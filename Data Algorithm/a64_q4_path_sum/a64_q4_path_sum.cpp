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

vector<int> k(8);
vector<vector<pii> > adj(25);
int mxw[25] = {};

bool dfs(int cur,int sum,int tag,int cap,vector<bool> &vis)
{    
    if(sum>tag || sum+cap<tag)return false;
    if(sum==tag)return true;
    
    
    for(int i=0;i<adj[cur].size();i++)
    {
        auto [w,v] = adj[cur][i];
        if(vis[v]==false && sum+w<=tag)
        {
            vis[v]=true;
            bool fg = dfs(v,sum+w,tag,cap-mxw[v],vis);
            if(fg)
            {
                return true;
            }
            vis[v]=false;
        }
    }
    

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;

    for(auto &i:k)cin >> i;

    while(m--)
    {
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].pb({w,b});
        adj[b].pb({w,a});
    }

    int cap=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            mxw[i] = max(mxw[i], adj[i][j].first);
        }
        cap += mxw[i];
    }

    
    vector<string> res;
    for(auto t:k)
    {
        bool fg=false;
        //fill(all(vis),false);
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n);
            vis[i] = true;
            fg = dfs(i,0,t,cap-mxw[i],vis);
            if(fg)break;
        }

        if(fg==true)
        {
            res.pb("YES\n");
        }
        else res.pb("NO\n");
    }

    for(auto i:res)
    {
        cout << i;
    }
    

    return 0;
}
/*
9 30
1122 847 845 805 2784 3199 3269 2129
1 3 147
6 8 294
3 4 365
3 5 222
0 7 137
6 7 192
4 8 453
4 5 337
0 3 109
2 7 304
0 2 239
0 4 66
2 3 442
0 5 128
0 8 218
4 6 50
5 7 131
3 6 235
1 7 320
5 6 456
3 8 499
1 2 362
7 8 184
2 8 304
1 4 338
2 4 49
5 8 89
1 5 169
3 7 92
1 6 477

*/