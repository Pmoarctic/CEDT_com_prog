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

struct ITEM
{
    string id;
    double total;

    bool operator<(const ITEM &x)const
    {
        if(x.total !=total)
        {
            return x.total<total;
        }
        else
        {
            return x.id>id;
        }
    }
};


int main()
{
    unordered_map<string,double> mp;
    unordered_map<string,int> idx;
    vector<ITEM> v;
    string str;
    int cnt=0;
    while(cin >> str)
    {
        if(str == "END")
        {
            break;
        }
        double p;
        cin >> p;
        mp[str] = p;
        v.pb({str,0});
        idx[str] = cnt;
        cnt++;
    }

    while(cin >> str)
    {
        v[idx[str]].total += mp[str];
    }

    sort(all(v));

    bool fg = 1;
    for(int i=0;i<sz(v);i++)
    {
        if(i>=3)break;
        if(v[i].total)
        {
            fg = 0;
            cout << v[i].id << " " << v[i].total << '\n';
        }
    }
    if(fg)
    {
        cout << "No Sales";
    }

}