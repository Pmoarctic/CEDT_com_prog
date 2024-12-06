#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > adj[1010];

int prim(int src,int n)
{
    int cnt=0;
    int res=0;
    vector<int> intree(n+1,0);
    //intree[src]=1;
    priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({0,src});

    while(!pq.empty())
    {
        auto [wei,cur] = pq.top();
        pq.pop();

        if(intree[cur]==1)continue;

        intree[cur]=1;
        cnt++;
        res+=wei;

        if(cnt == n)
        {
            return res;
        }

        for(auto [next_wei,next_node]:adj[cur])
        {
            if(intree[next_node] == 0)
            {
                pq.push({next_wei,next_node});
            }
        }
    }

    return res;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int wei,a,b;
        cin >> wei >> a >> b;
        adj[a].push_back({wei,b});
        adj[b].push_back({wei,a});
    }

    int res = prim(1,n);

    cout <<res;

}