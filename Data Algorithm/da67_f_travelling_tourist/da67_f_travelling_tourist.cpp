#include<bits/stdc++.h>
using namespace std;

int tour[10] = {};
vector<vector<long> > dis(505,vector<long>(505,INT_MAX));
int n,m,k;
long res = INT_MAX;
vector<bool> vis(505,0);
void recur(int go,long distant,int cur)
{

    if(go == k)
    {
        res = min(res,distant);
    }
    else
    {
        // cout << go << " ";
        for(int id=0;id<k;id++)
        {
            int i = tour[id];
            if(cur==i || vis[i]==1)continue;
            vis[i]=1;
            recur(go+1,distant+dis[cur][i],i);
            vis[i]=0;
        }
    }
}

int main()
{
    
    cin >> n >> m >> k;

    for(int i=0;i<k;i++)
    {
        cin >> tour[i];
    }

    for(int j=1;j<=m;j++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        dis[a][b] = c;
        dis[b][a] = c;
    }

    for(int k=1;k<=n;k++)
    {
            dis[k][k]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][k] != INT_MAX && dis[k][j] != INT_MAX && dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    // for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=n;j++)
    //         {
    //             cout << dis[i][j] <<" ";
    //         }
    //         cout << "\n";
    //     }

    for(int i=0;i<k;i++)
    {    
        vis[tour[i]]=1;
        recur(1,0,tour[i]);
        vis[tour[i]]=0;
    }
    
    cout << res;
}