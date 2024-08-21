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
    multiset<int> s;
    int n=10;
    while(n--)
    {  
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << *s.lower_bound(3);
}
/*

*/
