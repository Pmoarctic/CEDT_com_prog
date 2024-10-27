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

int mp[505][505];
int vis[505][505];
int n,m,T;
int res = 0;

struct SOURCE
{
    int r;
    int c;
    int time;
};


int main()
{
    
    cin >> n >> m >> T;
    queue<SOURCE> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mp[i][j];
            if(mp[i][j]==1)
            {
                q.push({i,j,T});
                res++;
            }
        }
    }

    while(!q.empty())
    {
        auto [i,j,t] = q.front();
        q.pop();
        if(i<0||i>=n||j<0||j>=m || mp[i][j]==2 || vis[i][j]==1 || t==-1)continue;

        vis[i][j]=1;
        if(mp[i][j]==0)
        {
            res++;
            mp[i][j]=1;
        }
        
        
        q.push({i+1,j,t-1});
        q.push({i-1,j,t-1});
        q.push({i,j+1,t-1});
        q.push({i,j-1,t-1});
    }


    // cout << '\n';
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout << mp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << res;


    return 0;
}