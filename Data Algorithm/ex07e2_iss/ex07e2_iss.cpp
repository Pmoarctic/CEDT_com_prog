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

int res=0;
void recur(int n,int sum,int start)
{
    if(sum > n)return;
    if(sum==n)
    {
        res++;
        return;
    }
    else
    {
        for(int i=start;i<=n;i++)
        {
            recur(n,sum+i,i);
        }
    }

}

int main()
{
    int n;
    cin >> n;

    recur(n,0,1);

    cout << res;


    return 0;
}