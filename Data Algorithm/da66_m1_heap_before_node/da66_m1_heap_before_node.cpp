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

int n,node;
vll res;
void recur(ll cur)
{
    if(cur >= n || cur==node)return;

    res.pb(cur);
    recur(cur*2+1);
    recur(cur*2+2);
}

int main()
{
    cin >> n >> node;

    recur(0);

    sort(all(res));

    cout << res.size() << "\n";
    //if(res.size()==0)return 1;
    for(auto i:res)
    {
        cout << i << " ";
    }

    return 0;
}