#include<bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

vector<int> reversal(vector<int> arr,int st,int ed)
{
    vector<int> newarr;
    for(int i=0;i<st;i++)
    {
        newarr.push_back(arr[i]);
    }
    for(int i=ed;i>=st;i--)
    {
        newarr.push_back(arr[i]);
    }
    for(int i=ed+1;i<arr.size();i++)
    {
        newarr.push_back(arr[i]);
    }

    return newarr;
}

vector<int> rev(vector<int> arr,int lastidx)
{
    if(arr[0] == pq.top())
    {
        return reversal(arr,0,lastidx);
        
    }
    for(int i=1;i<lastidx;i++)
    {
        if(arr[i] == pq.top())
        {
            return reversal(arr,0,i);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a,check;

    

    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
        a.push_back(tmp);
    }

    int last = a.size()-1;
    while(!pq.empty())
    {
        

        if(a[last]==pq.top())
        {
            pq.pop();
            last--;
        }
        else
        {
            for(auto i:a)cout << i << " ";
            cout << "\n";
            a = rev(a,last);
        }
    }
    for(auto i:a)cout << i << " ";
            cout << "\n";
}
//6 13
/*
3 1 2 5 4
*/