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

int ci[2010];
int co[2010];
int n,e;
vector<vi> adj(2010);
vector<int> dis(2010,INT_MAX);

void dijkstra(int src)
{   
    gpiiq pq;
    pq.push({0,src});
    dis[src]=0;

    while(!pq.empty())
    {
        auto [distance,current] = pq.top();
        pq.pop();

        for(auto i:adj[current])
        {
            if(dis[i] > dis[current] + co[current] + ci[i])
            {
                dis[i] = dis[current] + co[current] + ci[i];
                pq.push({dis[i],i});
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    for(int i=0;i<n;i++)
    {
        cin >> ci[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> co[i];
    }
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    dijkstra(0);
    
    for(int i=0;i<n;i++)
    {
        if(dis[i]==INT_MAX)cout << "-1 ";
        else cout << dis[i] << " ";
    }


    return 0;
}