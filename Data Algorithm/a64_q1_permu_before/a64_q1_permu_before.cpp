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



int main()
{
    int n,m,src;
    cin >> n >> m >> src;
    
    vector<vi> dis(n,vi(n,INT_MAX));
    while(m--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        dis[a][b] = c;
    }

    for(int k=0;k<n;k++)
    {
        dis[k][k]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(dis[i][j] > dis[i][k] + dis[k][j] && dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX)
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    vi res;
    bool fg=1;
    for(int i=0;i<n;i++)
    {
        res.pb(dis[src][i]);

        if(dis[i][i]<0)
        {
            fg=0;
            break;
        }
    }

    if(fg==0)
    {
        cout << -1;
        return 0;
    }
    for(auto i:res)
    {
        cout << i << " ";
    }

    return 0;
}