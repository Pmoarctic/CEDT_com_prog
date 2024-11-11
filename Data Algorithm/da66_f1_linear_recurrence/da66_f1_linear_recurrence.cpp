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

#define MOD 32717
int k,n;
int c[1010]={};
int a[1010]={};
vi memo(1010,-1);

int R(int N)
{
    if(memo[N]!=-1)
    {
        return memo[N];
    }
    /////
    if(N<k)
    {
        return a[N];
    }
    else
    {
        int sum = 0;
        for(int i=1;i<=N;i++)
        {
            sum += (c[i]*R(N-i))%MOD;
            sum %= MOD;
        }
        return memo[N] = sum%MOD;
    }
}


int main()
{
    cin >> k >> n;

    for(int i=1;i<=k;i++)
    {
        cin >> c[i];
    }
    for(int i=0;i<k;i++)
    {
        cin >> a[i];
    }

    cout << R(n);


    return 0;
}