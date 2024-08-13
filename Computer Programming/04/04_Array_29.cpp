#include<bits/stdc++.h>
using namespace std;

int overlap(vector<int> a,vector<int> b)
{
    int neg=0;
    for(int i=0;i<4;i++)
    {
        if(a[i]<=0 || b[i]<=0)
        {
            neg = min(neg,a[i]);
            neg = min(neg,b[i]);
        }
    }

    for(int i=0;i<4;i++)
    {
        a[i] += abs(neg);
        b[i] += abs(neg);
    }



    ////////////////
    int cnt=0;
    vector<vector<int> > arr(1000, vector<int>(1000,0));
    //a
    int sline = a[3]-1;
    int eline = a[1];
    int st = a[0];
    int ed = a[2]-1;
    for(int i=sline;i>=eline;i--)
    {
        for(int j=st;j<=ed;j++)
        {
            arr[i][j]++;
        }
    }

    //b
    sline = b[3]-1;
    eline = b[1];
    st = b[0];
    ed = b[2]-1;
    for(int i=sline;i>=eline;i--)
    {
        for(int j=st;j<=ed;j++)
        {
            arr[i][j]++;
        }
    }
    for(int i=sline;i>=eline;i--)
    {
        for(int j=st;j<=ed;j++)
        {
            //cout << arr[i][j];
            if(arr[i][j] == 2)
            {
                cnt++;
            }
        }
        //cout << endl;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > v;

    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v.push_back({a,b,c,d});
    }


    vector<vector<int> > res;
    int mx=-1;
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int tmp = overlap(v[i],v[j]);
            mx = max(mx,tmp);
            if(tmp!=0)
            {
                res.push_back({tmp,i,j});
            }
        }
    }

    if(res.size()==0)
    {
        cout << "No overlaps";
        return 0;
    }

    cout << "Max overlapping area = " << mx << '\n';
    for(int i=0;i<res.size();i++)
    {
        if(res[i][0] == mx)
        {
            cout << "rectangles " << res[i][1] << " and " << res[i][2] << '\n';
        }
    }
    

}

