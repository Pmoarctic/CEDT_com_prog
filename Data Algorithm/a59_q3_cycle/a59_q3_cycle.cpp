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

vector<int> adj[100010],vis(100010,0);
unordered_map<int,int> mp;

int res;

void depthFirstSearch(int cur,int prev,int idx)
{
    if(vis[cur] == 1)
    {
        return;
    }
    else
    {
        vis[cur]=1;
        mp[cur]=idx;
        for(auto i:adj[cur])
        {
            if(i!=prev)
            {
                if(vis[i]==1)
                {
                    //cout << "\n" << mp[i] << " " << mp[cur] << "\n";
                    res = mp[i]-mp[cur]+1;
                    return;
                }
                depthFirstSearch(i,cur,idx+1);
            }
        }
        return;
    }

}

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    depthFirstSearch(0,-1,1);

    cout <<res;
}

// detect cycle using dfs