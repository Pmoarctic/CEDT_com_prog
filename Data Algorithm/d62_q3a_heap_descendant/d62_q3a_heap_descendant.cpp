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

int res = 0;
vi v;
int n,a;
void recur(int cur)
{
    if(cur >= n)return;
    res++;
    v.pb(cur);
    recur(cur*2+1);
    recur(cur*2+2);
}

int main()
{
    cin >> n >> a;

    recur(a);
    sort(all(v));

    cout << res << "\n";
    for(auto &i:v)
        cout << i << " ";

    return 0;
}