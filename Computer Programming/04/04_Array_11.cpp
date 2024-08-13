#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int n=s.size();

    set<int> st;

    for(int i=0;i<=9;i++)
    {
        st.insert(i);
    }

    for(int i=0;i<n;i++)
    {
        int tmp = s[i]-'0';
        st.erase(tmp);
    }

/*
    for(auto i:st)
    {
        cout << i << ' ';
    }
*/

    vector<int> a;
    for(auto i:st)
    {
        a.push_back(i);
    }

    if(a.size()==0)
    {
        cout << "None";
        return 0;
    }

    for(int i=0;i<a.size()-1;i++)
    {
        cout << a[i] << ',';
    }
    cout << a[a.size()-1];

}