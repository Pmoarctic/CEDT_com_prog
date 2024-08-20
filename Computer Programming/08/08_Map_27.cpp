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

unordered_map<int,string> mp = {{2,"abc"}, {3,"def"}, {4,"ghi"}, {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"}};
unordered_map<char,string> mp2;
void init()
{
    string key = "";
    char cur = '2';
    int n = 1;
    for(char c='a';c<='o';c++)
    {
        if(n>3)
        {
            cur++;
            n=1;
            
        }
        for(int i=1;i<=n;i++)
        {
            key += cur;
        }
        //cout << key << "\n";
        mp2[c] = key;
        key="";
        n++;
    }
    mp2[' '] = "0";
    mp2['p'] = "7";
    mp2['q'] = "77";
    mp2['r'] = "777";
    mp2['s'] = "7777";

    mp2['t'] = "8";
    mp2['u'] = "88";
    mp2['v'] = "888";

    mp2['w'] = "9";
    mp2['x'] = "99";
    mp2['y'] = "999";
    mp2['z'] = "9999";
}

int main()
{  
    init();
    string str,cmd="";
    //cin.ignore();

    while(getline(cin,str))
    {
        //cout << str << '\n';
        int i=0;
        cmd = "";

        for(;i<str.size();i++)
        {
            if(cmd=="T2K" || cmd=="K2T")
            {
                i++;
                break;
            }
            cmd+=str[i];
        }
        
        string res="";
        if(cmd == "T2K")
        {
            for(;i<str.size();i++)
            {
                res += mp2[tolower(str[i])] + " ";
            }
        }
        else if(cmd=="K2T")
        {
            vector<string> vec;
            string tmp="";
            for(;i<str.size();i++)
            {
                if(str[i]==' ')
                {
                    vec.pb(tmp);
                    tmp = "";
                }
                else
                {
                    tmp += str[i];
                }
            }
            vec.pb(tmp);

            for(auto i:vec)
            {
                if(i[0] == '0')
                {
                    res += " ";
                }
                else
                {
                    res += mp[i[0]-'0'][i.size()-1];
                }
            }
        }

        cout << ">> " << res << '\n';
    }
}
/*

*/
