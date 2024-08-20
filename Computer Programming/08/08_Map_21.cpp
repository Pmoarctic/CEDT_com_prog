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
    unordered_map<string,vector<string> > mp;
    vector<string> order;
    unordered_map<string,bool> bo;

    string a;
    while(cin>>a)
    {
        string b;
        cin >> b;
        mp[b].pb(a);
        if(bo[b]==0)
        {
            bo[b]=1;
            order.pb(b);
        }
    }

    for(auto i:order)
    {
        auto v = mp[i];
        cout << i << ":";
        for(auto j:v)
        {
            cout << " " << j;
        }
        cout << "\n";
    }
}
/*

*/
