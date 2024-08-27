#include <iostream>
#include <vector>

using namespace std;

bool isLeap(int y) 
{
    y-=543;
    if (y % 4 == 0) 
    {
        if (y % 100 == 0) 
        {
            if (y % 400 == 0) 
            {
                return true;
            } 
            else 
            {
                return false;
            }
        } 
        else 
        {
            return true;
        }
    } 
    else 
    {
        return false;
    }
}

int main() {
    int d,m,y;
    cin >> d >> m >> y;
    
    vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(y))
    {
        month[1] = 29;
    }

    int res = 0;
    
    for (int i = 0; i < m - 1; ++i) 
    {
        res += month[i];
    }
    res += d;
    cout << res;

    return 0;
}
