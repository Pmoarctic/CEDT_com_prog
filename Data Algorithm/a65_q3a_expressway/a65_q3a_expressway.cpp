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

vector<pii> adj[705];
vector<int> dis(705,INT_MAX);
void dijkstra(int src)
{
    //gpiiq pq;
    queue<pair<int,int> > pq;
    pq.push({dis[src],src});

    while(!pq.empty())
    {
        auto [wei,cur] = pq.front();
        pq.pop();

        for(auto &i:adj[cur])
        {
            if(dis[cur]>=dis[2])
            {
                break;
            }
            if(dis[i.second] >= dis[cur] + i.first)
            {
                dis[i.second] = dis[cur] + i.first;
                pq.push({dis[i.second],i.second});
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt=1;

    int n,cost;
    cin >> n >> cost;
    adj[1].pb({cost,2});
    adj[2].pb({cost,1});
    dis[1]=0;
    dis[2]=cost;

    vector<int> res;
    for(int i=3;i<=n;i++)
    {
        int len;
        cin >> len;
        if(len==0)
        {
            res.pb(dis[2]);
            continue;
        }

        int add=0;
        for(int j=0;j<len;j++)
        {
            int ed,wei;
            cin >> ed >> wei;

            if(wei >= dis[2])
            {
                continue;
            }
            else
            {
                add++;
                adj[i].pb({wei,ed});
                adj[ed].pb({wei,i});
                cnt++;
            }
        }
        if(add!=0)dijkstra(1);
        res.pb(dis[2]);
    }


    for(auto i:res)
    {
        cout << i << " ";
    }

    return 0;
}
/*
21 700000
1 2 1
2 1 1 2 1
4 2 1 4 1 1 1 3 1
4 1 1 4 1 5 1 2 1
6 4 1 1 1 2 1 6 1 5 1 3 1
2 1 1 7 1
0
4 6 1 8 1 7 1 9 1
5 3 1 4 1 5 1 6 1 7 1
3 7 1 5 1 1 1
2 11 1 12 1
2 4 1 13 1
6 3 1 7 1 1 1 4 1 13 1 9 1
11 2 1 9 1 6 1 4 1 1 1 13 1 10 1 11 1 14 1 8 1 15 1
10 7 1 16 1 14 1 2 1 9 1 15 1 5 1 11 1 3 1 4 1
2 9 1 15 1
10 8 1 7 1 3 1 17 1 2 1 14 1 15 1 16 1 10 1 12 1
9 10 1 16 1 5 1 15 1 14 1 2 1 3 1 18 1 1 1
19 17 1 16 1 6 1 18 1 13 1 10 1 7 1 2 1 19 1 11 1 14 1 4 1 20 1 15 1 3 1 8 1 12 1 1 1 9 1
*/