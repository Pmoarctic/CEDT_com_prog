#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;

struct NUM
{
    int n;
    int st;
    int ed;

    bool operator<(const NUM &x)const
    {
        if(x.n!=n)
        {
            return x.n>n;
        }
        else
        {
            return x.st>st;
        }
    }
};


int main()
{
    vector<NUM> v;
    vi arr;
    int n;
    while(cin >> n)
    {
        arr.pb(n);
    }

    int size = 1;
    int cur = arr[0];
    int st=0;
    int i=1;
    for(;i<sz(arr);i++)
    {
        if(arr[i] != cur)
        {   
            size = max(size,i-st);
            st = i;
        }
        else if(arr[i] != cur)
        {
            st++;
            
        }
        cur = arr[i];
    }
    
    cur = arr[0];
    st=0;
    i=1;
    for(;i<sz(arr);i++)
    {
        if(arr[i] != cur && i-st ==size)
        {
            v.pb({arr[st],st,i});
            
            st = i;
        }
        else if(arr[i] != cur)
        {
            st++;
            
        }
        cur = arr[i];
    }
    if(i-st == size)
    {
        v.pb({arr[st],st,i});
    }

    sort(all(v));
    for(auto i:v)
    {
        printf("%d --> x[ %d : %d ]\n",i.n,i.st,i.ed);
    }


}