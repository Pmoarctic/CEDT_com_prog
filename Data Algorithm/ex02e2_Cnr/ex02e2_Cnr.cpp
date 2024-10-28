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

int C(int n,int k)
{
    if(n==k || k==0)
    {
        return 1;
    }
    else
    {
        return C(n-1,k-1)+C(n-1,k);
    }
}

int main()
{
    int n,k;
    cin >> n >> k;

    cout << C(n,k);
    return 0;
}