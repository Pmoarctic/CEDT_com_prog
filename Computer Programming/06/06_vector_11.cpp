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
    vi res;

    int n;
    cin >> n;
    bool ft = 0;
    while(1)
    {
        cin >> n;
        if(n==-1)
        {
            break;
        }
        if(ft)
        {
            res.insert(res.begin(),n);
        }
        else
        {
            res.pb(n);
        }
        ft = !ft;
    }


    cout << "[";
    for(int i=0;i<sz(res);i++)
    {
        if(i==sz(res)-1)
        {
            cout << res[i];
        }
        else
        {
            cout << res[i] << ", ";
        }
        
    }
    cout << "]";

}