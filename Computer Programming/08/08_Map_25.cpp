#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;


int main()
{  
    vector<pair<string,set<string> > > vec;
    unordered_map<string,int> mp;
    int cur = 0;

    int n;
    cin >> n;
    while(n--)
    {
        string id;
        cin >> id;
        mp[id] = cur;
        cur++;
        set<string> tmp;
        string t;
        while(cin>>t && t!="*")
        {
            tmp.insert(t);
        }
        vec.pb({id,tmp});
    }

    vector<string> res;
    string key;
    cin >> key;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i].first == key)
        {
            continue;
        }
        for(auto j:vec[i].second)
        {
            if(vec[mp[key]].second.find(j) != vec[mp[key]].second.end())
            {
                res.pb(vec[i].first);
                break;
            }
        }
    }

    if(res.size()==0)
    {
        cout << ">> Not Found";
        return 0;
    }
    for(auto i:res)
    {
        cout << ">> " << i << "\n";
    }

}
/*

*/
