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
        vector<vector<double> > R(n,vector<double>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> R[i][j];
            }
        }
//////////////////////////////////
//warshal
        bool fg = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(R[i][j] < R[i][k] * R[k][j])R[i][j] = R[i][k] * R[k][j];

                    if(i==j && R[i][i]>1)
                    {
                        fg=1;
                        breeak;
                    }
                }
                if(fg)break;
            }
            if(fg)break;
        }
        res.pb((fg)?"YES\n":"NO\n");

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
0.75 0.7 1
2
1 0.7
1.2 1
*/