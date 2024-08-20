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

struct TICKET
{
   int no;
   int time;
};


queue<TICKET> q;

int main()
{
    int n;
    int cur;
    cin >> n;
    TICKET curticket;
    int totaltime=0;
    int nq=0;
    while(n--)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "reset")
        {
            int st;
            cin >> st;
            cur = st;
        }
        else if(cmd == "new")
        {
            int t;
            cin >> t;
            cout << ">> ticket " << cur << "\n";
            q.push({cur,t});
            cur++;
        }
        else if(cmd == "next")
        {
            curticket = q.front();
            cout << ">> call " << curticket.no << "\n";
            q.pop();
        }
        else if(cmd == "order")
        {
            int t;
            cin >> t;
            cout << ">> qtime " << curticket.no << " " << t-curticket.time << "\n";
            totaltime += t-curticket.time;
            nq++;
        }
        else
        {
            double res = (double)totaltime/(double)nq;
            cout << ">> avg_qtime " << round(res*100)/100 << "\n";
        }
    }

}
/*
14
reset 301
new 1100
new 1110
next
order 1120
new 1130
next
next
order 1161
avg_qtime
new 1170
next
order 1180
avg_qtime
*/
