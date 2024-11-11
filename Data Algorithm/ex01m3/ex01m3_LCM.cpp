#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
typedef vector<ull> vull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull n,m;
    cin >> n >> m;

    vector<ull> num(n);
    for(auto &i:num)cin >> i;

    ull mxq=0;
    vector<ull> que(m);
    for(ull &i:que)cin >> i;  

    mxq = *(max_element(que.begin(),que.end()));

    //find lcm
    ull lcm = num[0];
    for(ull i=1;i<n;i++)
    {
        lcm = (num[i]*lcm)/(gcd(num[i],lcm));
    }
    //

    vector<ull> time;

    bool fg=0;
    //for(int i=0;i<n;i++)time.pb(0);
    for(ull t=1;t<=lcm;t++)
    {
        for(ull i:num)
        {
            if(t%i==0)
            {
                time.pb(t);
            }
            if(time.size() > mxq)
            {
                fg=1;
                break;
            }
        }
        if(fg)
        {
            break;
        }
    }



    ull len = time.size();
    for(ull c:que)
    {
        if(c<=n)
        {
            cout << "0\n";
            continue;
        }
        c-=n;
        ull q,r;
        r = c%len;
        q = c/len;
        if(r==0)
        {
            q--;
            r = len;
        }

        cout << lcm*q + time[r-1] << "\n";
    }


    return 0;
}

