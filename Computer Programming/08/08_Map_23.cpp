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

struct SONG
{
    string genre;
    int mn=0;
    int sc=0;
};

bool sorttime(SONG &a,SONG &b)
{
    if(a.mn!=b.mn)
    {
        return a.mn>b.mn;
    }
    else
    {
        return a.sc>b.sc;
    }
}
 
unordered_map<string,SONG> mp;
vector<SONG> vec;

int main()
{  
    string song,name,gen,time;
    while(cin >> song)
    {
        cin >> name >> gen >> time;
        int a=0,b=0;
        bool fg=0;
        for(int i=0;i<time.size();i++)
        {
            //cout << time[i]<< "\n";
            if(fg==0)
            {
                if(time[i]==':')
                {
                    fg=1;
                    continue;
                }
                else
                {
                    a *= 10;
                    a += time[i]-'0';
                }
            }
            else
            {
                b *= 10;
                b += time[i]-'0';
            }
            
        }
        //cout << a << " " << b << '\n';
        mp[gen].genre=gen;
        mp[gen].mn+=a;
        mp[gen].sc+=b;
    }

    for(auto i:mp)
    {
        i.second.mn += i.second.sc/60;
        i.second.sc %= 60;
        vec.pb(i.second);
    }
    sort(all(vec),sorttime);
    for(int i=0;i<sz(vec);i++)
    {
        if(i>=3)break;
        cout << vec[i].genre << " --> " << vec[i].mn <<":" << vec[i].sc << "\n";
    }

}
/*

*/
