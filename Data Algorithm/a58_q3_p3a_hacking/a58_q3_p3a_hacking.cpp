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

vector<int> c,start,adj[50010];

vector<int> tim(50010,INT_MAX);
void hack(int st)
{
    priority_queue<pii, vector<pii> , greater<pii> > pq;// time,node;
    pq.push({c[st],st});
    tim[st] = c[st];

    while(!pq.empty())
    {
        auto [total,cur] = pq.top();
        pq.pop();

        for(auto i:adj[cur])
        {
            if(tim[i] > total+c[i])
            {
                tim[i] = total+c[i];
                pq.push({tim[i],i});
            }
        }

    }
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    while(k--)
    {
        int t;
        cin >> t;
        start.pb(t);
    }

    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        c.pb(t);
    }

    while(m--)
    {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(auto i:start)
    {
        hack(i);
    }

    int res=-1;
    for(int i=0;i<n;i++)
    {
        res = max(res,tim[i]);
    }
    cout << res;
}

//multi src shortest path