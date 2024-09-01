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

struct EDGE
{
    int st,ed,cost;

    bool operator <(const EDGE &a)const
    {
        return a.cost>cost;
    }
};

unordered_map<int,int> parent;

int findparent(int p)
{
    if(parent[p]!=p)
    {
        parent[p] = findparent(parent[p]);
    }
    return parent[p];
}

ull MSTkruskal(priority_queue<EDGE> &pq)
{
    ull total_wei = 0;

    while(!pq.empty())
    {
        auto [a,b,w] = pq.top();
        pq.pop();

        if(findparent(a) != findparent(b))
        {
            total_wei += w;
            parent[findparent(a)] = findparent(b);
        }
    }
    return total_wei;
}



int main()
{
    int n;
    cin >> n;
    //init
    priority_queue<EDGE> pq;
    //

    vector<int> keep;
    while(n--)
    {
        int t;
        cin >> t;
        parent[t]=t;
        for(auto i:keep)
        {
            pq.push({t,i,t^i});
        }
        keep.pb(t);
    }
    ull res = MSTkruskal(pq);
    
    cout << res;


    return 0;
}

//kruskal