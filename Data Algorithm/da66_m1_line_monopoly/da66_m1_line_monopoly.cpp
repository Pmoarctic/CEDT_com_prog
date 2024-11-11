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



void INSERT(set<pair<int,int> > &s, int left, int right)
{
    auto itr = s.lower_bound({left,right});

    if(itr!=s.begin() && (--itr)->second+1<left)itr++;

    while(itr!=s.end() && (itr)->first<=right+1)
    {
        left = min(left,itr->first);
        right = max(right,itr->second);
        itr = s.erase(itr);
    }
    s.insert({left,right});
}

set<pair<int,int> > s;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int q;
    cin >> q;
    int cmd,a,b;
    while(q--)
    {
        cin >> cmd;
        if(cmd==1)
        {
            cin >> a >> b;
            INSERT(s,a,b);

        }
        else
        {
            cout << s.size() << "\n";
        }

    }

    return 0;
}