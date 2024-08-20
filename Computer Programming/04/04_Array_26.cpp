#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int idx;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int tmp;
            cin >> tmp;

            if(tmp != 0)
            {
                v.push_back(tmp);
            }
            else
            {
                idx = i;
            }
        }
    }

    int cnt=0;
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i]>v[j])
            {
                cnt++;
            }
        }
    }

    if(n%2==1 && cnt%2==0)
    {
        cout << "YES";
    }
    else if(n%2==0)
    {
        if((cnt%2==0 && idx%2==1) || (cnt%2==1 && idx%2==0))
        {
            cout << "YES";
        }
        else
        {
            cout <<"NO";
        }
    }
    else
    {
        cout << "NO";
    }


}
/* line=2
4 1 5 2 7 3 6 8
cnt=7
*/

/*
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/
