#include<bits/stdc++.h>
using namespace std;

int n,m;
int mp[2010][2010]={};
int lay[2010][2010] = {};

void bfs(int src_i,int src_j)
{
    //i,j,layer
    queue<tuple<int,int,int> > q;
    q.push({src_i,src_j,0});

    while(!q.empty())
    {
        auto [i,j,layer] = q.front();
        q.pop();

        if(i<0||j<0||i>=n||j>=m||mp[i][j]==0)
        {
            continue;
        }
        else
        {
            lay[i][j] = layer;
            mp[i][j] = 0;
            q.push({i+1,j,layer+1});
            q.push({i-1,j,layer+1});
            q.push({i,j+1,layer+1});
            q.push({i,j-1,layer+1});
        }
    }
}

int main()
{
    vector<pair<int,int> > locate;

    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mp[i][j];
            if(mp[i][j]==2)
            {
                locate.push_back({i,j});
            }
        }
    }

    bfs(0,0);

    // cout << "\n";
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout << lay[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int res=0;
    for(auto i:locate)
    {
        res += lay[i.first][i.second];
    }

    cout << res*2;

}