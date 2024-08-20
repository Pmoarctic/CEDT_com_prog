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

struct STUDENT
{
    string id;
    double grade=0;
    vector<string> order;
    string got;
};

unordered_map<string,int> mp;
vector<STUDENT> vec;

bool sortid(STUDENT &a,STUDENT &b)
{
    return a.id < b.id;
}

bool sortgrade(STUDENT &a,STUDENT &b)
{
    return a.grade > b.grade;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string a;
        int b;
        cin >> a >> b;
        mp[a] = b;
    }

    cin >> n;
    while(n--)
    {
        string a, c,d,e,f;
        double b;
        cin >> a >> b >> c >> d >> e >> f;
        vec.pb({a,b,{c,d,e,f},""});
    }

    sort(all(vec),sortgrade);

    /*
    for(auto i:vec)
    {
        cout << i.id << " " << i.grade << " " << i.order[0] << " " << i.order[1] << " " << i.order[2] << " " << i.order[3] <<'\n';
    }
    cout << '\n';
    */

    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<4;j++)
        {
            if(mp[vec[i].order[j]] > 0)
            {
                vec[i].got = vec[i].order[j];
                mp[vec[i].order[j]]--;
                break;
            }
        }
    }

    sort(all(vec),sortid);

    for(auto i:vec)
    {
        cout << i.id << " " << i.got <<'\n';
    }
    

}
/*

*/
