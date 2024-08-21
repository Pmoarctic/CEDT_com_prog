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

unordered_map<string,int> mp = {{"A",1},{"B+",2},{"B",3},{"C+",4},{"C",5},{"D+",6},{"D",7},{"F",8}};
unordered_map<int,string> mp2 = {{1,"A"},{2,"B+"},{3,"B"},{4,"C+"},{5,"C"},{6,"D+"},{7,"D"},{8,"F"}};

struct STUDENT
{
    string id;
    int grade;
    int order;
};

vector<STUDENT> vec;
unordered_map<string,int> idx;

int main()
{
    int cur = 0;
    string a,b;
    while(cin >> a && a!="q")
    {
        cin >> b;
        vec.pb({a,mp[b],cur});
        idx[a]=cur;
        cur++;
    }

    

    while(cin >> a)
    {
        int id = idx[a];
        //  cout << id << '\n';
        vec[id].grade--;
        if(vec[id].grade==0)
        {
            vec[id].grade++;
        }
    }
    for(auto i:vec)
    {
        cout << i.id << " " << mp2[i.grade] << "\n";
    }
    

}
/*

*/
