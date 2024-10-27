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
    vi a,s;
    for(int i=1;i<=n;i++)
    {
        a.pb(i);
        int t;
        cin >> t;
        s.pb(t);
    }
    sort(all(s));

    if(a==s)cout << "YES";
    else cout <<"NO";



    return 0;
}