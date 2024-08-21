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

int main()
{  
    int n;
    cin >> n;

    vector<int> arr(2000,0);
    int mx=-1;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        for(int i=a;i<b;i++)
        {
            arr[i]++;
            mx = max(mx,arr[i]);
        }
    }
    cout << mx;
}