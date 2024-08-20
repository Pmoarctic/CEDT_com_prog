#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[7][7]={}

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> arr[i][j];
        }
    }



    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(table1[i][j] == 1)
            {
                //up
                int x=j,y=i;
                y--;
                while(y>=1)
                {
                    res[y][x] = 0;
                    y--;
                }
                //
                //down
                x=j,y=i;
                y++;
                while(y<=n)
                {
                    res[y][x] = 0;
                    y++;
                }
                //
                //left
                x=j,y=i;
                x--;
                while(x>=1)
                {
                    res[y][x] = 0;
                    x--;
                }
                //
                //right
                x=j,y=i;
                x++;
                while(x<=n)
                {
                    res[y][x] = 0;
                    x++;
                }
                //
                /////////////////
                //up right
                x=j,y=i;
                x++;
                y--;
                while(x<=n && y>=1)
                {
                    res[y][x] = 0;
                    x++;
                    y--;
                }
                //
                //up left
                x=j,y=i;
                x--;
                y--;
                while(x>=1 && y>=1)
                {
                    res[y][x] = 0;
                    x--;
                    y--;
                }
                //
                //down right
                x=j,y=i;
                x++;
                y++;
                while(x<=n && y<=n)
                {
                    res[y][x] = 0;
                    x++;
                    y++;
                }
                //
                //down left
                x=j,y=i;
                x--;
                y++;
                while(x>=1 && y<=n)
                {
                    res[y][x] = 0;
                    x--;
                    y++;
                }
                //
                
            }
        }
    }



    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(res[i][j] == 1)
            {
                cout << "Q";
            }
            else
            {
                cout << "-";
            }
        }
        cout << "\n";
    }
}

/*
8
Q-------
-------Q
-Q------
------Q-
------Q-
--QQ----
--------
----Q---
*/