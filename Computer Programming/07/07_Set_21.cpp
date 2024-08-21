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
    set<int> st;

    int k;
    cin >> k;
    int t;
    while(cin >> t)
    {
        st.insert(t);
    }

    int cnt=0;
    for(auto i:st)
    {
        int target = k-i;
        if(target == i)
        {
            continue;
        }
        if(st.find(target)in(st))
        {
            //cout << target << " " << i << "\n";
            st.erase(target);
            st.erase(i);
            cnt++;
        }
    }
    cout << cnt;
}
/*

*/
