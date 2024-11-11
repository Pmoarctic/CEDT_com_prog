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

int V,E;
bool coloring(vector<vi> &adj, vi &color, int amount, int cur)
{
    if(cur == V)return true;
    for(int cl=1;cl<=amount;cl++)
    {
        bool can_color = true;
        for(auto i:adj[cur])
        {
            if((cl == color[i]))can_color=false;
        }

        if(can_color)
        {
            color[cur] = cl;
            if(coloring(adj,color,amount,cur+1))return true;
            color[cur] = 0;
        }

        
    }
    return false;
}

int main()
{
    
    cin >> V >> E;

    vector<vi> adj(V);
    while(E--)
    {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int l=1,r=V,ans=V;
    int mid;

    while(l<=r)
    {
        mid = (l+r)/2;
        vi color(V);
        if(coloring(adj,color,mid,0))
        {
            ans = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }

    cout << ans;


    return 0;
}