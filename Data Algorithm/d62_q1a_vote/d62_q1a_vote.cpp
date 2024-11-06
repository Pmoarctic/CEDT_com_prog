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
    int n,k;
    cin >> n >> k;
    unordered_map<string,int> mp;
    while(n--)
    {
        string s;
        cin >> s;
        mp[s]++;
    }

    vector<int> v;
    for(auto i:mp)
    {
        v.pb(i.second);
    }
    sort(all(v));

    if(v.size() <= k)
    {
        cout << v[0];
        return 0;
    }
    int to_find = v[v.size()-k];
    int cnt=1;
    while(to_find == 0)
    {
        to_find = v[v.size()-k+cnt];
        cnt++;
    }

    //cout << to_find << "<-\n";
    auto res = lower_bound(all(v),to_find) - v.begin();

    cout << v[res];

    // for(auto i:v)
    // {
    //     cout << i << " ";
    // }



    return 0;
}