#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
typedef vector<int> vi;

int n, m, h, q;
int mx = 0;
multiset<int> net;
vector<int> dis, res, res2;

int main() {
    cin >> n >> m >> h >> q;

    dis.resize(2000000, 0);
    res2.resize(n + 1, -1);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x < dis.size()) {
            dis[x] = y;
            mx = max(mx, x);
        } else {
            cout << "Error: x out of bounds\n";
            return 1;
        }
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        net.insert(t);
    }

    res.pb(0);
    int cnt = 0;

    for (int i = 1; i <= mx; i++) {
        if (dis[i] != 0) {
            int delta = abs(dis[i] - h);
            auto it = net.lower_bound(delta);
            if (it != net.end()) {
                net.erase(it);
                cnt++;
            }
        }
        res.pb(cnt);
        if (net.empty()) {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if(i>cnt)
        {
            break;
        }
        auto it = lower_bound(res.begin(), res.end(), i);
        if (it != res.end()) {
            res2[i] = distance(res.begin(), it);
        }
        else
        {
            break;
        }
    }

    while (q--) {
        int k;
        cin >> k;
        if (k > cnt) {
            cout << "-1\n";
        } else {
            cout << res2[k] << "\n";
        }
    }

    return 0;
}
