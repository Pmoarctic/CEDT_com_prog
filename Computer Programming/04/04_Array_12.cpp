#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string> mp = {{"Robert", "Dick"},
{"William", "Bill"},
{"James", "Jim"},
{"John", "Jack"},
{"Margaret", "Peggy"},
{"Edward", "Ed"},
{"Sarah", "Sally"},
{"Andrew", "Andy"},
{"Anthony", "Tony"},
{"Deborah", "Debbie"},
{"Dick","Robert"},
{"Bill", "William"},
{"Jim", "James"},
{"Jack", "John"},
{"Peggy", "Margaret"},
{"Ed", "Edward"},
{"Sally", "Sarah"},
{"Andy", "Andrew"},
{"Tony", "Anthony"},
{"Debbie", "Deborah"}};

int main()
{
    int n;
    cin >> n;
    while(n--)
    {   
        string tmp;
        cin >> tmp;

        if(mp.find(tmp)==mp.end())
        {
            cout << "Not found\n";
        }
        else
        {
            cout << mp[tmp] << "\n";
        }
    }

}