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
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,a;
        cin >> n >> a;
        cout << max( (n*n+n)/2 , n*a) << '\n';
    }

    return 0;
}
/*

*/
