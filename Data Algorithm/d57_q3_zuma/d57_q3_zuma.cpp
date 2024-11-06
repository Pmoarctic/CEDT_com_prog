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

int main()
{
    int n,pos,ball;
    cin >> n >> pos >> ball;

    int t;
    list<int> lis(n);
    for(auto &i:lis)
    {
        cin >> i;
    }
    auto itr = lis.begin();
    while(pos--)
    {
        itr++;
    }
    itr = lis.insert(itr,ball);

    auto left = itr;
    auto right = itr;
    int bo = 0;
    while(!lis.empty())
    {
        int l=0,r=0;
        while(*left == *(--left))l++;
        while(*right == *(++right))r++;
        left++;
        int len = l+r+1;
        if(len>=3 && (l>=1 || bo==0))
        {
            while(len--)
            {
                left = lis.erase(left);
            }
        }
        else
        {
            break;
        }
        bo++;
    }

    for(auto i:lis)
    {
        cout << i << " ";
    }

    return 0;
}