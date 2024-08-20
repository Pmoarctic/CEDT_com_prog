#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> num,res;
    for(int i=0;i<n;i++)
    {
        double tmp;
        cin >> tmp;
        num.push_back(tmp);
    }

    for(int i=0;i<n;i++)
    {
        //double sum=0;
        double down=num[i];
        for(int j=i-1;j>=0;j--)
        {
            down = num[j] + (1/down);
        }
        res.push_back(down);
    }

    for(auto i:res)
    {
        cout << setprecision(10) << i << "\n";
    }
}