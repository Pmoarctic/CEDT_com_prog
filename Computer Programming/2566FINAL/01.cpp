#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define in(x) != x.end()
#define endl '\n';
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;

int main()
{  
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int mn = INT_MAX;
        int sum=0;
        while(n--)
        {
            int tmp;
            cin >>tmp;
            mn =min(mn,tmp);
            sum += tmp;
        }

        cout << sum-mn << endl;
    }
}