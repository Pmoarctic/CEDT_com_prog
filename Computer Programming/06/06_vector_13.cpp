#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string line, char delimiter)
{
    vector<string> res;
    string tmp = "";
    for(int i=0;i<line.size();i++)
    {
        if(tmp.size()!=0 && line[i]==delimiter)
        {
            res.push_back(tmp);
            tmp = "";
        }
        else if(line[i]!=delimiter)
        {
            tmp += line[i];
        }
    }
    if(tmp.size()!=0)
    {
        res.push_back(tmp);
    }
    return res;
}
int main()
{
    string line;
    getline(cin, line);
    string delim;
    getline(cin, delim);
    for (string e : split(line, delim[0]))
    {
    cout << '(' << e << ')';
    }
}