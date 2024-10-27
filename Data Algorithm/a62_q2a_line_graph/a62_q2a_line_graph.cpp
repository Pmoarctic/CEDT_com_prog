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
void dfs(int &flag,int cur,int prev,int src)
{
    if(vis[cur]==1)
    {
        flag=0;
        return;
    }
    if(adj[cur].size()>2)
    {
        flag=0;
    }
    vis[cur]=1;

    for(auto i:adj[cur])
    {
        if(i==prev)continue;
        dfs(flag,i,cur,src);
    }
}


int main()
{
    int n,m;
    cin >> n >> m;

    while(m--)
    {
        int a,b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int res=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            int flag=1;
            dfs(flag,i,-1,i);
            res += flag;
        }
    }

    cout << res;

    return 0;
}