#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> res,noo;
    noo.push_back(0);
    int n;
    cin >> n;
    int arr[n+1][3] = {};//[no.][st,ed,0=down 1=up 2=stay]
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin >> tmp >> arr[i][0] >> arr[i][1];
        noo.push_back(tmp);
        arr[i][2] = (arr[i][0] < arr[i][1]) + (arr[i][0]==arr[i][1])*2;
    }
    int m;
    cin >> m;
    while(m--)
    {
        int st,ed;
        cin >> st >> ed;
        int no=0;
        int mn=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            int sum=0;
            int cur = arr[i][0];
            int go = arr[i][2];
            bool fg=0;
            bool rub=0;
            if(go == 2)
            {
                go = (arr[i][0] < st);
            }
            while(true)
            {
                if(cur == arr[i][1] && fg != 1)
                {
                    fg = 1;
                    go = 2;
                }
                if(cur == ed && rub == 1)
                {
                    break;
                }
                if(cur == st && rub != 1)
                {
                    rub = 1;
                    if(fg == 1)
                    {
                        go = 2;
                    }
                }

                //cout << cur << "\n";
                if(go == 2)
                {
                    if(rub == 1 && fg == 1)
                    {
                        go = cur < ed;
                    }
                    else if(rub == 1)
                    {
                        
                    }
                    else if(fg == 1)
                    {
                        go = cur < st;
                    }
                }
                if(go==0)
                {
                    cur--;
                    if(fg==1)
                    {
                        sum++;
                    }
                }
                else if(go==1)
                {
                    cur++;
                    if(fg==1)
                    {
                        sum++;
                    }
                }
                
            }
            if(sum < mn)
            {
                mn = sum;
                no = noo[i];
            }
            else if(sum == mn)
            {
                if(no > noo[i])
                {
                    no = noo[i];
                }
            }
            //cout << sum <<'\n';

        }
        res.push_back(no);
        //cout << ">> " << no << "\n";
    }
    for(auto i:res)
    {
        cout << ">> " << i << "\n";
    }
}
/*
4
1 3 1
2 1 8
3 2 2
4 12 3
1
3 2
*/