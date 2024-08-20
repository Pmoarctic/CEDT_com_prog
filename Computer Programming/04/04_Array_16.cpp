#include<bits/stdc++.h>
using namespace std;

vector<string> cut(vector<string> arr)
{
    vector<string> newdeck;
    int a = 0;
    int b = (arr.size()/2);
    for(int i=b;i<arr.size();i++)
    {
        newdeck.push_back(arr[i]);
    }

    for(int i=a;i<b;i++)
    {
        newdeck.push_back(arr[i]);
    }

    return newdeck;
}

vector<string> shuffle(vector<string> arr)
{
    vector<string> newdeck;
    int a = 0;
    int b = (arr.size()/2);
    for(int i=b;i<arr.size();i++)
    {
        newdeck.push_back(arr[a]);
        newdeck.push_back(arr[i]);
        a++;
    }
    return newdeck;
}

int main()
{
    int n;
    cin >> n;
    vector<string> card;
    for(int i=0;i<n;i++)
    {
        string c;
        cin >> c;
        card.push_back(c);
    }

    string s;
    cin.ignore();
    getline(cin,s);
    string C = "C",S = "S";
    for(int i=0;i<s.size();i++)
    {
        string k="";
        k+=s[i];
        if(k==C)
        {
            card = cut(card);
        }
        else if(k == S)
        {
            card = shuffle(card);
        }
    }

    for(auto i:card)
    {
        cout << i << " ";
    }
}