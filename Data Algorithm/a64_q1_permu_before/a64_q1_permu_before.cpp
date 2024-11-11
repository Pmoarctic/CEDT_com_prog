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

void recur(vector<int> &tmp, vector<vi> &res,vi &vis,vi &con)
{
    if(tmp.size()==n)
    {
        res.pb(tmp);
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0 && (con[i]==-1 || vis[con[i]]==1))
            {
                tmp.pb(i);
                vis[i]=1;
                recur(tmp,res,vis,con);
                vis[i]=0;
                tmp.pop_back();
            }
        }
    }

}

int main()
{
    
    cin >> n >> m;

    vi con(n,-1);

    while(m--)
    {
        int a,b;
        cin >> a >> b;
        con[b] = a;
    }

    vector<vi> res;
    vi vis(n,0);
    vi tmp;
    recur(tmp,res,vis,con);

    sort(all(res));
    for(auto i:res)
    {
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << '\n';
    }

    return 0;
}