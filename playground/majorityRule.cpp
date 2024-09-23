#include<bits/stdc++.h>
using namespace std;


int main()
{
    clock_t sssss,eeeee;
    sssss = clock();

    unordered_map<int,int> cnt;
    int mx = -1;
    int res = INT_MAX;
    int n;
    cin >> n;
    int t;
    while(n--)
    {
        cin >> t;
        cnt[t]++;
        //cout << cnt[t] << '\n';
        int tmp;
        if(mx <= cnt[t])
        {
            mx = cnt[t];
            tmp = t;
        }

        res = min(res,tmp);

    }

    eeeee = clock();
    double time_taken = double(eeeee - sssss) / double(1000000);
    if(time_taken>1.0){cout << "time limit exceed\n";}
    else
    {
        cout << res;
    }

    // for(auto i:cnt)
    // {
    //     cout << i.first << " " << i.second << '\n';
    // }
}