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


unordered_map<string,int> mp = {{"soon",0}, {"neung",1},{"song",2},
                                {"sam",3} , {"si",4}   ,{"ha",5},
                                {"hok",6} , {"chet",7} ,{"paet",8}, 
                                {"kao",9} , {"et",1}   ,{"yi",2},
                                {"sip",10}, {"roi",100},{"phan",1000},{"muen",10000},{"saen",100000},{"lan",1000000} };

int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s[0]=='q')break;

        vector<string> word;
        string tmp = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                word.pb(tmp);
                tmp = "";
            }
            else
            {
                tmp += s[i];
            }            
        }
        word.pb(tmp);

        int num=0;
        int k=0;
        int i=0;
        if(word[0] == "sip")
        {
            i=1;
            k = 10;
        }
        for(;i<word.size();i++)
        {
            if((0 <=mp[word[i]] && mp[word[i]] <= 9))
            {
                num += k;
                k = mp[word[i]];
            }
            else if(word[i]=="sip" && k>10)
            {
                k += 10;
            }
            else
            {
                k *= mp[word[i]];
            }
            //cout << k << "\n";
        }
        cout << num+k << "\n";
    }

}
/*

*/
