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
    int n;
    cin >> n;
    vi arr[n*2];
    for(int i=1;i<n*2;i++)
    {
        arr[i].pb(0);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int t;
            cin >> t;
            t += arr[i-j+n][arr[i-j+n].size()-1];
            arr[i-j+n].pb(t);
        }
    }
    for(int i=1;i<n*2;i++)
    {
        for(auto j:arr[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
// greedy algorithm
