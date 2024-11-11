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

set<string> res;

void build_front_and_back(int n,int k,string src)
{
    queue<string> q;
    q.push(src);

    while(n--)
    {
        queue<string> tmp;
        
        while(!q.empty())
        {
            string cur = q.front();
            q.pop();

            tmp.push("0" + cur);
            tmp.push("1" + cur);
        }
        q=tmp;
        //cout << q.size() << "\n";
    }

    while(k--)
    {
        queue<string> tmp;
        
        while(!q.empty())
        {
            string cur = q.front();
            q.pop();

            tmp.push(cur + "0");
            tmp.push(cur + "1");
        }
        q=tmp;
        //cout << q.size() << "\n";
    }

    while(!q.empty())
    {
        res.insert(q.front());
        //cout << q.front() << "\n";
        q.pop();
    }
    return;
}



int main()
{
    int n,b;
    cin >> n >> b;

    int fill = n-b;

    string og = "";
    //build template
    for(int i=0;i<b;i++)
    {
        og += "1";
    }
    //
    for(int i=0;i<=fill;i++)
    {
        //cout << i << " " << fill-i << "\n";
        build_front_and_back(i,fill-i,og);
    }

    for(auto i:res)
    {
        cout << i << "\n";
    }

    return 0;
}