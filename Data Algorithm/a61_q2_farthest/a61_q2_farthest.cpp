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
typedef vector<pii> vpii;
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

vector<int> dijkstra(int node, int src, vector<vpii> &adj)
{
    vector<int> dis(node+1,INT_MAX);
    dis[src]=0;
    gpiiq pq;
    pq.push({0,src});

    while(!pq.empty())
    {
        int cur = pq.top().second;
        pq.pop();

        for(auto i:adj[cur])
        {
            int cost = i.first;
            int next = i.second;
            if(dis[next] > dis[cur] + cost)
            {
                dis[next] = dis[cur] + cost;
                pq.push({dis[next],next});
            }
        }
    }
    return dis;
}

int main()
{
    int n;
    cin >> n;
    vector<vpii> adj(n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int c;
            cin >> c;
            if(c>0)
            {
                adj[i].pb({c,j});
            }
        }
    }

    vi keep = dijkstra(n,1,adj);
    int res = -1;

    for(int i=2;i<=n;i++)
    {
        res = max(res,keep[i]);
    }

    if(res == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << res;

    return 0;
}
// dijkstra choosing largest distance city

/*
5
0 1 -1 -1 7
-1 0 2 3 5
-1 -1 0 4 -1
-1 4 2 0 -1
-1 -1 -1 4 0
*/

/*
7
0 5 0 0 0 5 0
5 0 5 0 0 0 0
0 5 0 5 0 0 0
0 0 5 0 5 0 0
0 0 0 5 0 5 0
5 0 0 0 5 0 0 
0 0 0 0 0 0 0
*/