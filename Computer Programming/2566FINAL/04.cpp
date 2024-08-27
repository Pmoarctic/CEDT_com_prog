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

struct TEAM
{
    int win=0;
    vector<int> score;
    bool stat=0;
};

vector<pair<TEAM,TEAM> > vec;



int main()
{   
    int nn;
    cin >> nn;
    while(nn--)
    {

    string team1,team2;
    cin >> team1 >> team2;
    int win1=0,win2=0;
    string sc;
    vector<int> t1,t2;
    while(cin >> sc && sc!="*")
    {
        int score1=0,score2=0;
        int t=0;
        for(int i=0;i<sc.size();i++)
        {
            if(sc[i] == '-')
            {
                score1=t;
                t=0;
            }
            else
            {
                t*=10;
                t+=sc[i]-'0';
            }
        }
        score2 = t;
        t1.pb(score1);
        t2.pb(score2);
        ////////////
        if(score1>score2)
        {
            win1++;
        }
        else
        {
            win2++;
        }
    }
    if(win1>win2)
    {
        cout << "*" << team1 << " " << win1 << " [ ";
        for(auto i:t1)cout << i << " ";
        cout << "]\n";

        cout << team2 << " " << win2 << " [ ";
        for(auto i:t2)cout << i << " ";
        cout << "]\n";
    }   
    else
    {
        cout << team1 << " " << win1 << " [ ";
        for(auto i:t1)cout << i << " ";
        cout << "]\n";

        cout << "*" << team2 << " " << win2 << " [ ";
        for(auto i:t2)cout << i << " ";
        cout << "]\n";
    }


    }
}

/*
1
USA Columbia 25-12 25-12 25-13 *

2
Columbia Korea 25-12 14-25 20-25 25-20 15-9 *
Thailand Slovania 25-21 25-23 25-18 *

3
Korea Slovania 13-25 20-25 23-25 *
Columbia Slovania 17-25 25-19 26-24 18-25 11-15 *
USA Slovania 25-13 25-13 20-25 25-13 *
*/