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
    set<int> s;
    int n;
    int fg = 0;
    while(cin >> n)
    {
        if(s.find(n)==s.end())
        {
            s.insert(n);
        }
        else
        {
            fg=1;
            break;
        }
    }

    while(cin >> n)
    {

    }

    if(fg)
    {
        cout << s.size()+1;
        return 0;
    }
    cout << -1;
    
}
/*

*/
