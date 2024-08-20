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

/*
2
USD 35.3065
AUD 23.8617
100 THB THB
*/

int main()
{  
    unordered_map<string,double> mp;
    mp["THB"] = 1;
    int n;
    cin >> n;
    while(n--)
    {
        string a;
        double b;
        cin >> a >> b;
        mp[a] = b;
    }

    int money;
    string cur;
    cin >> money;
    cin >> cur;

    vi res1;
    vector<string> res2;
    res1.pb(money);
    res2.pb(cur);

    string next;
    while(cin >> next)
    {
        double from = (double)money*mp[cur];
        money = (int)(from/mp[next]);
        cur = next;
        res1.pb(money);
        res2.pb(cur);
    }
    for(int i=0;i<res1.size()-1;i++)
    {
        cout << res1[i] << " " << res2[i] << " -> ";
    }
    cout << res1[res1.size()-1] << " " << res2[res1.size()-1];
}
/*

*/
