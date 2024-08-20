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

int n=0;
int table[6][6] = {};
int table2[6][6] = {};
vector<int> v[200];
unordered_map<char,int> mp = {{'B',1},{'I',2},{'N',3},{'G',4},{'O',5}};
unordered_map<int,char> mp2 = {{1,'B'},{2,'I'},{3,'N'},{4,'G'},{5,'O'}};

bool check(int y,int x)
{
    bool f=0;
    int cnt;
    /////////////////////////////
    cnt=0;
    for(int i=1;i<=5;i++)
    {
        if(table[y][i]==0)
        {
            cnt++;
        }
    }
    if(cnt==5)
    {
        if(!f)cout << n << '\n';
        f=1;
        for(int i=1;i<=4;i++)
        {
            if(table2[y][i]==0)
            {
                continue;
            }
            cout<<mp2[i]<<table2[y][i]<<", ";
        }
        cout<<mp2[5]<<table2[y][5]<<'\n';
    }
    ////////////////////////

    cnt=0;
    for(int i=1;i<=5;i++)
    {
        if(table[i][x]==0)
        {
            cnt++;
        }
    }
    if(cnt==5)
    {
        if(!f)cout << n << '\n';
        f=1;
        for(int i=1;i<=4;i++)
        {
            if(table2[i][x]==0)
            {
                continue;
            }
            cout<<mp2[x]<<table2[i][x]<<", ";
        }
        cout<<mp2[x]<<table2[5][x]<<'\n';
    }
    /////////////////////////

    cnt=0;
    for(int i=1;i<=5;i++)
    {
        if(table[i][i]==0)
        {
            cnt++;
        }
    }
    if(cnt==5)
    {
        if(!f)cout << n << '\n';
        f=1;
        for(int i=1;i<=4;i++)
        {
            if(table2[i][i]==0)
            {
                continue;
            }
            cout<<mp2[i]<<table2[i][i]<<", ";
        }
        cout<<mp2[5]<<table2[5][5]<<'\n';
    }
    /////////////////////////

    cnt=0;
    for(int i=1;i<=5;i++)
    {
        if(table[6-i][i]==0)
        {
            cnt++;
        }
    }
    if(cnt==5)
    {
        if(!f)cout << n << '\n';
        f=1;
        for(int i=1;i<=4;i++)
        {
            if(table2[6-i][i]==0)
            {
                continue;
            }
            cout<<mp2[i]<<table2[6-i][i]<<", ";
        }
        cout<<mp2[5]<<table2[1][5]<<'\n';
    }
    /////////////////////////


   return f;
}

int main()
{
    char cc;
    cin >> cc >> cc >> cc >> cc >> cc;
    v['B'].pb(0);
    v['I'].pb(0);
    v['N'].pb(0);
    v['G'].pb(0);
    v['O'].pb(0);

    char c[6] = {'B','I','N','G','O'};
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            char ch = c[j-1];
            string num;
            cin >> num;
            if(num[0] == '*')
            {
                table[i][j] = 0;
                v[ch].pb(0);
            }
            else
            {
                table[i][j] = stoi(num);
                v[ch].pb(stoi(num));
            }
            table2[i][j] = table[i][j];
        }
    }

    string tmp;
    bool fg=0;
    while(cin >> tmp)
    {
        n++;
        if(fg)continue;

        char l = tmp[0];
        int num;
        if(tmp.size()==2)
        {
            num = tmp[1]-'0';
        }
        else
        {
            num = (tmp[1]-'0')*10 + (tmp[2]-'0');
        }
        for(int i=1;i<=5;i++)
        {
            if(num == v[l][i])
            {
                table[i][mp[l]] = 0;

                fg = check(i,mp[l]);
            }
        }
    }

/*
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cout << table[i][j] << " ";
        }
        cout << '\n';
    }
    */


}
