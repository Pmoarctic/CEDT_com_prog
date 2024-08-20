#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    double arr[n+1][m+1];
    vector<vector<double> > v;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=2;i<=n-1;i++)
    {
        vector<double> tmp;
        for(int j=2;j<=m-1;j++)
        {
            double sum = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1];
            sum += arr[i][j-1] + arr[i][j] + arr[i][j+1];
            sum += arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1];
            tmp.push_back(sum/9.0);
        }
        v.push_back(tmp);
    }

    for(auto i:v)
    {
        for(auto j:i)
        {
            cout << round(j*100)/100.0 << " ";
        }
        cout << "\n";
    }
}