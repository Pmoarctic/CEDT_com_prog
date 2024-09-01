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
    vector<vi> arr(n+2,vi(n+2,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> arr[i][j];
        }
    }

    int res=-1;
    for(int i=n;i>=1;i--)
    {
        for(int j=n;j>=1;j--)
        {
            arr[i][j] += arr[i+1][j+1];
            res = max(res,arr[i][j]);
        }
    }

    cout << res;
    return 0;
}
// greedy algorithm