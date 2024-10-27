#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define in(x) != x.end()
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;

int main()
{
    int k;
    cin >> k;

    vector<string> res;
    while(k--)
    {
        int n;
        cin >> n;
        vector<vector<double> > R(n,vector<double>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> R[i][j];
            }
        }
//////////////////////////////////
//warshal
        vector<double> dis(n,DBL_MAX);
        dis[0]=0;
        for(int l=0;l<n-1;l++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dis[j] > dis[i] - log(R[i][j]))
                    {
                        dis[j] = dis[i] - log(R[i][j]);
                    }
                }
            }
        }
//////////////////////////
        bool fg=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dis[j] > dis[i] - log(R[i][j]))
                {
                    fg=1;
                    break;
                }
            }
            if(fg)break;
        }
        if(fg)
        {
            res.pb("YES\n");
        }
        else
        {
            res.pb("NO\n");
        }
////////////////////////////////////
    }
    for(auto i:res)
    {
        cout << i;
    }

    return 0;
}
/*
2
3
1 0.7 1.2
1.1 1 2
0.75 0.7 1 2
1 0.7
1.2 1
*/