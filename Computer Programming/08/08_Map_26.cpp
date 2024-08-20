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
    set<string> res;

    unordered_map<string,vector<string> > mp;
    vector<string> arr;

    string str;
    while(cin >> str)
    {
        arr.pb(str);
    }

    for(int i=0;i<arr.size()-1;i+=2)
    {
        mp[arr[i]].pb(arr[i+1]);
        mp[arr[i+1]].pb(arr[i]);
    }
    string st = arr[arr.size()-1];
    res.insert(st);
    for(int i=0;i<mp[st].size();i++)
    {
        res.insert(mp[st][i]);
        string next = mp[st][i];
        for(int j=0;j<mp[next].size();j++)
        {
            res.insert(mp[next][j]);
        }
    }

    for(auto i:res)
    {
        cout << i << "\n";
    }
    

}
/*

*/
