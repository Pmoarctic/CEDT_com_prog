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
    int t;
    cin >> t;
    while(t--)
    {
        int a1,a2,a3,a4,b1,b2,b3,b4,n;
        int cnt=0;
        cin >> n >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;

        for(int i=a1;i<=b1;i++)for(int j=a2;j<=b2;j++)for(int k=a3;k<=b3;k++)for(int l=a4;l<=b4;l++)
        {
            if(i+j+k+l == n)
            {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}