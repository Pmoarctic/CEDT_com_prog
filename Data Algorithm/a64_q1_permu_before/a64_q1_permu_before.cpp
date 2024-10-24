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

vector<int> cond(22,INT_MAX);
void permu(string res,int n,vector<bool> &vis)
{
    for(int i=res.size()-2;i>=0;i--)
    {
        if(cond[res[res.size()-1]-'0'] == res[i]-'0' && cond[res[res.size()-1]-'0'] != INT_MAX)
        {
            return;
        }
    }

    if(res.size()==n)
    {
        cout << res << "\n";
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                permu(res + to_string(i),n,vis);
                vis[i]=0;
            }
        }

        return;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<bool> vis(n,false);

    
    int m;
    cin >> m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        cond[a]=b;
    }

    permu("",n,vis);



    return 0;
}