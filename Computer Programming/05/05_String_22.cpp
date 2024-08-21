#include<bits/stdc++.h>
using namespace std;



int main()
{
    string x,y;
    cin >> x >> y;
    int xmin=0,ymin=0,mxx=0,mxy=0;

    for(int i=0;i<y.size();i++)
    {
        int stx=0,sty=i;
        int cnt=0;
        while(stx<x.size() && sty<y.size())
        {
            if(x[stx]==y[sty])
            {
                cnt++;
            }
            stx++;
            sty++;
        }
        if(cnt>mxx)
        {
            mxx = cnt;
            xmin = i;
        }
    }

    for(int i=0;i<x.size();i++)
    {
        int stx=i,sty=0;
        int cnt=0;
        while(stx<x.size() && sty<y.size())
        {
            if(x[stx]==y[sty])
            {
                cnt++;
            }
            stx++;
            sty++;
        }
        if(cnt>mxy)
        {
            mxy = cnt;
            ymin = i;
        }
    }

    cout << mxx << " " << mxy << '\n';


    if(mxx > mxy)
    {
        while(xmin--)cout <<"-";
        cout << x << '\n';
        cout << y << "\n" << mxx << '\n';
    }
    else if(mxx < mxy)
    {
        cout << x << '\n';
        while(ymin--)cout <<"-";
        cout << y << "\n" << mxy <<'\n';
        
    }
    else
    {
        if(ymin < xmin)
        {
            cout << x << '\n';
            while(ymin--)cout <<"-";
            cout << y << "\n" << mxy <<'\n';
        }
        else
        {
            while(xmin--)cout <<"-";
            cout << x << '\n';
            cout << y << "\n" << mxx << '\n';
        }
    }

}
/*
AAAAAAAAAA
GGGAAAAAAAAA
*/