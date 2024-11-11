#include <bits/stdc++.h>

using namespace std;

#define ALL(a) a.begin(), a.end()
typedef unsigned long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a;
    cin >> n >> a;
    vector<int> time(n);
    for (auto &e : time) cin >> e;
    while (a--)
    {
        ll c, ans=ULLONG_MAX;
        cin >> c;

        if(c<=n)
        {
            cout << "0\n";
            continue;
        }

        ll l=1,r=ULLONG_MAX;
        while (l <= r){
            ll m = l + (r - l)/2;
            ll tt = 0;
            for (auto e : time)
                tt += (m/e + 1);
            if (tt >= c){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}