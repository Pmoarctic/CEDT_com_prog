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

bool sortgrade(STUDENT &a,STUDENT &b)
{
    if(a.grade != b.grade)
    {
        return a.grade < b.grade;
    }
    else
    {
        return a.order < b.order;
    }
}

int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        string t1,t2;
        cin >> t1 >> t2;
        idx[t1] = i;
        vec.pb({t1,mp[t2],i});
    }

    string s;
    while(cin >> s)
    {
        string curid="";
        for(int i=0;i<s.size()-1;i++)
        {
            curid+=s[i];
        }
        char cmd = s[s.size()-1];

        if(cmd == '-')
        {
            vec[idx[curid]].grade++;
            if(vec[idx[curid]].grade > 8)
            {
                vec[idx[curid]].grade--;
            }
            //cout << vec[idx[curid]].id << " " << vec[idx[curid]].grade << "\n";
        }
        else if(cmd == '+')
        {
            vec[idx[curid]].grade--;
            if(vec[idx[curid]].grade < 1)
            {
                vec[idx[curid]].grade++;
            }
            //cout << vec[idx[curid]].id << " " << vec[idx[curid]].grade << "\n";
        }
    }

    sort(all(vec),sortgrade);

    cout <<'\n';
    for(auto i:vec)
    {
        cout << i.id << " " << mp2[i.grade] << "\n";
    }

}
/*

*/
