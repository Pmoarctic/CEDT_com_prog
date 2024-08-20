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
    set<string> team,lose;
    string a,b;
    while(cin >> a)
    {
        cin >> b;
        team.insert(a);
        team.insert(b);
        lose.insert(b);
    }
    bool fg=0;
    for(auto i:team)
    {
        if(lose.find(i)==lose.end())
        {
            fg=1;
            cout << i << " ";
        }
    }
    if(fg==0)
    {
        cout << "None";
    }
    
}
/*

*/
