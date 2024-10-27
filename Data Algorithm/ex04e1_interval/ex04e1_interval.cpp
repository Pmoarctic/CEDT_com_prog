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
    vector<pii> v;

    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        v.pb({0,a});

    }
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        v[i].first = a;
    }
    sort(all(v));

    int res = 0;
    int cur_end = 0;
    for(int i=0;i<n;i++)
    {
        //cout << v[i].first << " " << v[i].second << "\n";
        if(cur_end <= v[i].second)
        {
            res++;
            cur_end = v[i].first;
            //cout << cur_end << "\n";
        }
        
    }
    cout << res;
    return 0;
}