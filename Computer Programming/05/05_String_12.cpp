#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define st first
#define nd second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;


int main()
{
    string s;
    int mx = -1;
    vector<string> num;
    while(cin >> s && s!="END")
    {
        mx = max(mx,sz(s));
        num.pb(s);
    }

    for(int i=0;i<sz(num);i++)
    {
        while(sz(num[i]) != mx)
        {
            num[i] = "0" + num[i];
        }
    }

    int sum=0;
    vi res;
    for(int j=mx-1;j>=0;j--)
    {
        for(int i=0;i<sz(num);i++)
        {
            sum += num[i][j] - '0';
        }
        res.pb(sum%10);
        sum/=10;
    }
    while(sum!=0)
    {
        res.pb(sum%10);
        sum/=10;
    }

    for(int i=sz(res)-1;i>=0;i--)
    {
        cout << res[i];
    }
}