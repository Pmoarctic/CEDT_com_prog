#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> res;
    int n;
    string m;
    cin >> n >> m;

    // string tmp = "[1,2,";
    // tmp += m + "],";

    string tmp = "1-(";
    tmp += m + ")-2";

    res.push_back(tmp);

    for(int i=3;i<=n;i++)
    {
        int len;
        cin >> len;
        while(len--)
        {
            string a,b;
            cin >> a >> b;
            // tmp = "[";
            // tmp += to_string(i) + "," + a + "," + b + "],";

            tmp = "";
            tmp += to_string(i) + "-(" + b + ")-" + a;

            res.push_back(tmp);
        }
    }

    for(auto i:res)
    {
        cout << i << "\n";
    }
}