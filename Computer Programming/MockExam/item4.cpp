#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,total;
    cin >> n >> total;
    int target = 0;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
        target += t;
    }
    target -= total;

    bool bo=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j] == target)
            {
                cout << i << " " << arr[i] << "\n";
                cout << j << " " << arr[j];
                bo = 1;
                break;
            }
        }
        if(bo)
        {
            break;
        }
    }

}