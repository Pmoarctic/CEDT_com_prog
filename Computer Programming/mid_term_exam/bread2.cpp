#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int res = 0;

    // Iterate over each bead as the start point
    for(int start = 0; start < n; start++) {
        int sum_without_removal = 0;
        int sum_with_removal = 0;
        int last = arr[start];
        bool removed = false;

        // First, calculate the max sum without any removal
        for(int i = start; i < start + n; i++) {
            if(arr[i % n] < last) {
                break;
            }
            sum_without_removal += arr[i % n];
            last = arr[i % n];
        }

        // Now, calculate the max sum with removing one bead
        for(int i = start; i < start + n; i++) {
            if(!removed && arr[i % n] < last) {
                removed = true; // Skip this bead
                continue;
            }
            if(arr[i % n] < last) {
                break;
            }
            sum_with_removal += arr[i % n];
            last = arr[i % n];
        }

        res = max({res, sum_without_removal, sum_with_removal});
    }

    cout << res << endl;
    return 0;
}
