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

int n,m;

void bfs(vector<pii> src,vector<vi> &dis,vector<vi> &mp)
{
    queue<pii> q;
    for(auto [i,j]:src)
    {
        q.push({i,j});
        dis[i][j]=0;
    }

    while(!q.empty())
    {
        auto [i,j] = q.front();
        q.pop();

        if(i+1<n && mp[i+1][j]!=3 && dis[i+1][j]==INT_MAX)
        {
            q.push({i+1,j});
            dis[i+1][j] = dis[i][j]+1;
        }
        if(i-1>=0 && mp[i-1][j]!=3 && dis[i-1][j]==INT_MAX)
        {
            q.push({i-1,j});
            dis[i-1][j] = dis[i][j]+1;
        }
        if(j+1<m && mp[i][j+1]!=3 && dis[i][j+1]==INT_MAX)
        {
            q.push({i,j+1});
            dis[i][j+1] = dis[i][j]+1;
        }
        if(j-1>=0 && mp[i][j-1]!=3 && dis[i][j-1]==INT_MAX)
        {
            q.push({i,j-1});
            dis[i][j-1] = dis[i][j]+1;
        }
    }

}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    cin >> n >> m;

    vector<pii> C1,C2;

    vector<vi> mp(n,vi(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mp[i][j];
            if(mp[i][j]==1)C1.pb({i,j});
            if(mp[i][j]==2)C2.pb({i,j});
        }
    }

    vector<vi> dis1(n,vi(m,INT_MAX));
    vector<vi> dis2(n,vi(m,INT_MAX));

    bfs(C1,dis1,mp);
    bfs(C2,dis2,mp);

    int res = INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dis1[i][j]==INT_MAX || dis2[i][j]==INT_MAX)
            {
                continue;
            }
            res = min(res, dis1[i][j]+dis2[i][j]);
        }
    }

    cout << res+1;

///////////////////////////DEBUG
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         if(dis1[i][j]==INT_MAX)cout << "x ";
    //         else cout << dis1[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         if(dis2[i][j]==INT_MAX)cout << "x ";
    //         else cout << dis2[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
////////////////////////////////////////

    return 0;
}