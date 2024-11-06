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

multiset<int> ms;
int main()
{
    int n,m;
    cin >> n >> m;
    while(n--)
    {
        int t;
        cin >> t;
        ms.insert(t);
    }

    while(m--)
    {
        int x;
        cin >> x;

        bool fg=0;
        for(auto i:ms)
        {
            if(ms.find(x-i)!=ms.end())
            {
                if(x-i==x/2 && ms.count(x-i)<2)
                {
                    break;
                }
                fg=1;
                break;
            }
        }

        if(fg)cout <<"YES\n";
        else cout << "NO\n";
    }

    return 0;
}