#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define in(x) != x.end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef priority_queue<pii, vector<pii> , greater<pii> > gpiiq;
#define MOD 100000007;

int main()
{
    ll n;
    cin >> n;

    ll a = 1;
    ll b = 2;

    ll res = 3;

    for(int i=2;i<=n;i++)
    {
        ll new_a = a+b;
        ll new_b = a*2 + b;
        a = new_a%MOD;
        b = new_b%MOD;
        //res = a+b;
    }

    //cout << a << " " << b << "\n";
    cout << (a+b)%MOD;

    return 0;
}