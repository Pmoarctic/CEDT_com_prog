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
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    set<pair<int,int> > s;
    int n,m;
    cin >> n >> m;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        s.insert({a,b});
    }

    vector<pair<int,int> > res;
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        if(s.find({a,b}) != s.end())
        {
            res.pb({0,0});
        }
        else if(s.upper_bound({a,b}) == s.begin())
        {
            res.pb({-1,-1});
        }
        else
        {
            auto itr = s.upper_bound({a,b});
            itr--;
            res.pb(*itr);
        }
    }

    for(auto i:res)
    {
        cout << i.first << " " << i.second << " ";
    }



    return 0;
}