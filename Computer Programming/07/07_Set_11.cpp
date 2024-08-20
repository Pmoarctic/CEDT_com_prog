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

multiset<char> set1,set2;

int main()
{
    string s1,s2;
    
    getline(cin,s1);
    getline(cin,s2);
    int n1 = sz(s1);
    int n2 = sz(s2);

    for(int i=0;i<n1;i++)
    {
        if(s1[i] == ' ')
        {
            continue;
        }
        set1.insert(tolower(s1[i]));
    }
    for(int i=0;i<n2;i++)
    {
        if(s2[i] == ' ')
        {
            continue;
        }
        set2.insert(tolower(s2[i]));
    }

    
    if(set1 == set2)
    {
        cout << "YES";
    }
    else cout << "NO";

}
/*

*/
