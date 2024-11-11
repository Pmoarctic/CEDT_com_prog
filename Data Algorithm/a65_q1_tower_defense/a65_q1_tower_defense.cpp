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

int main()
{
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    int res=0;
    vi p(m),h(m),t(k);
    for(auto &i:p)cin >> i;
    for(auto &i:h)cin >> i,res+=i;
    for(auto &i:t)cin >> i;

    sort(all(p));

    for(auto i:t)
    {
        
        int l = i-w;
        int r = i+w;
        int idx = lower_bound(all(p),l)-p.begin();
        bool not_shoot=1;
        while(not_shoot)
        {
            if(p[idx]<=r && h[idx]>0)
            {
                h[idx]--;
                res--;
                not_shoot=0;
            }
            if(p[idx]>=r || idx >= p.size())
            {
                not_shoot=0;
            }
            idx++;
        }
    }

    cout << res;


    return 0;
}