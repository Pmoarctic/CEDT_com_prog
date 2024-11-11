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
//vector<string> res;

void recur(string ans,int i,int j,vector<vi> &mp)
{
    if(i<0 || i>=n || j<0 || j>=m || mp[i][j]==1)
    {
        return;
    }
    if(i==n-1 && j==m-1)
    {
        cout << ans << "\n";
        //res.pb(ans);
    }
    else
    {
        mp[i][j]=1;
        recur(ans+"A",i,j+1,mp);
        mp[i][j]=0;

        mp[i][j]=1;
        recur(ans+"B",i+1,j,mp);
        mp[i][j]=0;

        mp[i][j]=1;
        recur(ans+"C",i-1,j,mp);
        mp[i][j]=0;

        return;
    }
}

int main()
{
    cin >> n >> m;

    vector<vi> mp(n+1,vi(m+1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mp[i][j];
        }
    }

    recur("",0,0,mp);

    // for(auto i:res)
    // {
    //     cout << i <<'\n';
    // }
    cout << "DONE";


    return 0;
}