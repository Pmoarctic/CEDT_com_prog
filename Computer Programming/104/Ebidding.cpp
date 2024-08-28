#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define all(x) x.begin(),x.end()

map<string,set<string> > board;
map<string,map<string,int> > bidder,order;

struct PLAYER
{
    string name;
    int price;
    int idx;
};

bool sorting(PLAYER &a,PLAYER &b)
{
    if(a.price!=b.price)
    {
        return a.price>b.price;
    }
    else
    {
        return a.idx<b.idx;
    }
}

set<string> name;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        char cmd;
        cin >> cmd;
        if(cmd=='B')
        {
            string a,b;
            ll p;
            cin >> a >> b >> p;

            name.insert(a);

            if(board[b].find(a) == board[b].end())
            {
                board[b].insert(a);
                bidder[b][a] = p;
            }
            else
            {
                bidder[b][a] = p;
            }
            order[b][a]=i;
        }
        else
        {
            string a,b;
            cin >> a >> b;
            if(board[b].find(a) != board[b].end())
            {
                //cout << "del\n";
                board[b].erase(a);
                bidder[b][a] = 0;
            }
        }
    }

    map<string,pair<int,vector<string> > > res;

    for(auto i:name)
    {
        res[i].first=0;
        vector<string> tt;
        res[i].second=tt;
    }

    for(auto i:board)
    {
        vector<PLAYER> tmp;

        for(auto j:i.second)
        {
            tmp.pb({j,bidder[i.first][j],order[i.first][j]});
        }
        sort(all(tmp),sorting);
        if(tmp.empty())
        {
            continue;
        }
        res[tmp[0].name].first += tmp[0].price;
        res[tmp[0].name].second.pb(i.first);
    }

    for(auto i:name)
    {
        if(res[i].first==0)
        {
            cout << i << ": $" << res[i].first << '\n';
            continue;
        }
        else
        {
            cout << i << ": $" << res[i].first << " ->";
            for(auto j:res[i].second)
            {
                cout << " " << j;
            }
            cout << '\n';
        }
        
    }

    
    return 0;
}
/*
16
B abc01 xyz05 200
B abc02 xyz04 400
B abc01 xyz03 100
B abc02 xyz02 500
B abc01 xyz01 300
W abc01 xyz03
B abc09 xyz99 999
B abc09 xyz98 999
B abc09 xyz97 999
B abc09 xyz96 999
W abc09 xyz99
B abc09 xyz95 999
B abc17 xyz17 17
B abc18 xyz18 18
B abc19 xyz19 19
W abc17 xyz17
*/

/*
200
B B16 P90 102
B B19 P83 102
B B19 P85 102
B B17 P91 101
B B10 P89 103
B B12 P83 102
B B19 P80 100
B B15 P90 103
B B11 P82 100
B B14 P90 101
B B17 P84 103
B B16 P86 101
B B13 P85 102
B B17 P90 102
B B16 P90 103
W B15 P90
B B12 P93 101
B B15 P85 103
W B16 P86
B B11 P80 103
W B15 P90
B B17 P92 103
W B17 P91
B B13 P86 102
B B11 P84 102
W B17 P90
B B10 P80 103
B B12 P81 102
B B16 P92 102
W B10 P80
B B19 P93 102
W B17 P92
B B10 P93 100
B B17 P86 100
W B12 P83
B B19 P81 101
B B19 P87 102
B B18 P82 101
B B14 P94 102
B B13 P83 100
W B10 P93
W B12 P81
B B16 P81 100
B B16 P83 102
B B16 P94 101
B B15 P94 100
B B18 P83 103
B B16 P94 102
B B14 P94 103
B B11 P93 100
B B12 P91 101
B B15 P90 102
B B10 P82 101
B B17 P86 103
B B11 P93 103
B B12 P85 103
B B19 P86 101
B B12 P85 101
W B14 P90
B B18 P88 100
B B12 P92 102
B B16 P85 100
B B11 P84 101
B B19 P92 100
B B16 P87 100
B B13 P80 100
B B17 P85 103
B B15 P85 101
B B12 P92 101
B B18 P86 102
B B19 P82 100
B B13 P86 103
B B12 P83 101
W B12 P83
B B19 P85 103
W B11 P82
B B17 P81 103
B B17 P82 103
W B11 P84
B B19 P86 100
B B10 P90 103
W B12 P91
B B17 P89 100
B B14 P83 100
B B17 P94 103
B B11 P81 103
B B13 P92 101
B B18 P89 103
B B16 P93 102
B B14 P92 103
B B13 P81 101
W B11 P82
B B10 P81 100
B B18 P91 101
B B11 P94 100
W B14 P94
B B15 P94 102
B B19 P85 102
B B14 P83 100
B B16 P85 102
B B19 P86 101
B B19 P87 103
W B12 P92
W B12 P85
B B10 P82 100
B B12 P84 100
W B18 P91
B B19 P93 103
B B15 P84 100
B B18 P91 101
B B15 P91 101
B B11 P88 102
W B19 P85
W B16 P90
B B16 P94 101
W B17 P94
B B10 P88 103
B B13 P88 103
W B16 P86
B B17 P87 102
B B12 P83 103
B B11 P94 102
B B16 P91 103
B B13 P86 101
B B14 P91 102
W B18 P86
B B11 P88 102
B B13 P90 103
B B13 P87 102
B B14 P91 102
B B15 P92 101
B B17 P91 102
B B16 P92 102
B B14 P83 102
B B19 P83 103
W B11 P84
B B10 P85 101
W B16 P90
B B15 P84 101
B B16 P91 101
B B16 P92 103
B B10 P93 102
B B14 P83 101
W B16 P94
W B15 P92
B B14 P91 100
B B10 P88 101
B B13 P92 102
B B10 P90 100
B B10 P91 103
B B18 P85 103
B B17 P90 102
B B14 P93 101
B B10 P93 102
B B19 P83 100
B B18 P84 102
B B11 P81 102
B B13 P92 100
B B12 P91 102
B B14 P88 100
W B19 P80
B B18 P89 102
B B16 P86 103
B B16 P83 101
B B17 P91 100
B B14 P91 103
W B16 P83
B B15 P92 100
B B11 P88 103
W B14 P91
W B12 P83
B B16 P81 100
B B18 P91 103
W B19 P87
B B15 P83 103
B B18 P85 101
B B19 P89 101
B B14 P87 101
B B10 P89 101
B B16 P86 102
B B15 P88 100
B B14 P90 102
B B12 P94 101
B B10 P88 100
W B11 P94
B B13 P84 103
B B15 P87 101
B B15 P83 102
B B17 P82 101
B B13 P80 103
B B17 P82 100
B B12 P90 101
B B10 P92 101
B B13 P83 103
B B19 P87 102
B B12 P84 102
B B18 P93 103
B B17 P81 102
W B13 P92
B B10 P81 100
*/