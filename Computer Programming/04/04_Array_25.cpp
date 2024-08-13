#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int hei=0;
    int wide = n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        hei = max(hei,tmp);
    }

    int arr[hei+1][wide+1] = {};

    ////generate
    for(int i=1;i<=wide;i++)
    {
        int st = hei - v[i-1] + 1;
        for(;st<=hei;st++)
        {
            arr[st][i] = 1;
        }
    }
    //////////////

    int res=0;
    for(int i=1;i<=hei;i++)
    {
        int l=0,r=wide;
        while(arr[i][l]!=1)
        {
            l++;
        }
        while(arr[i][r]!=1)
        {
            r--;
        }
        for(int st=l;st<=r;st++)
        {
            if(arr[i][st]==0)
            {
                arr[i][st] = 8;
                res++;
            }
        }
    }


    //////////////////

/*
    for(int i=1;i<=hei;i++)
    {
        for(int j=1;j<=wide;j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    */
    cout << res;


}

/*
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/
