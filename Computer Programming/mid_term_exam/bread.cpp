#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }

    int res=0;
    int l,r;
    for(int start=0;start<n;start++)
    {
        
        for(int cut=start+1;cut<start+n;cut++)
        {
            int sum = arr[start];
            int last = arr[start];
            for(int i=start+1;i<start+n;i++)
            {
                if(last <= arr[i%n])
                {
                    sum += arr[i%n];
                    last = arr[i%n];
                }
                else
                {
                    break;
                }
            }
            res = max(res,sum);


            sum = arr[start];
            last = arr[start];
            for(int i=start+1;i<start+n;i++)
            {
                if(i%n==cut%n)
                {
                    continue;
                }
                //cout << i%n << " ";
                //sum += arr[i%n];
                if(last <= arr[i%n])
                {
                    sum += arr[i%n];
                    last = arr[i%n];
                }
                else
                {
                    break;
                }
            }
            //cout << "\n" << sum << "\n";
            res = max(res,sum);
        }
        //cout << "\n";
    }
    cout << res;
}