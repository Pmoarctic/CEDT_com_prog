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
    unordered_map<string,string> mp;
    int n;
    cin >>n;
    while(n--)
    {
        string s,d;
        cin >> s >> d;
        mp[s]=d;
        mp[d]=s;
    }
    int q;
    cin >> q;
    while(q--)
    {
        string s;
        cin >> s;
        if(mp[s] == "")
        {
            cout << "Not found\n";
        }
        else cout << mp[s] << '\n';
    }

}
/*

*/
