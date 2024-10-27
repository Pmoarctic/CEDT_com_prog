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

vector<pii> adj[1200];

int prim(int src)
{
    //vector<int> dis(1200,INT_MAX);
    //dis[src] = 0;
    gpiiq pq;
    pq.push({0,0});

    vector<bool> intree(1200,0);
    //intree[src] = 1;

    int res = 0;

    while(!pq.empty())
    {
        auto [wei,cur] = pq.top();
        pq.pop();

        if(intree[cur] == 1)
        {
            continue;
        }
        intree[cur] = 1;
        res += wei;

        for(auto i:adj[cur])
        {
            if(intree[i.second] == 0)
            {
                pq.push({i.first,i.second});
            }
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int a;
            cin >> a;
            adj[i].pb({a,j});
            adj[j].pb({a,i});
        }
    }
    
    int res = prim(0);
    cout << res;

    return 0;
}