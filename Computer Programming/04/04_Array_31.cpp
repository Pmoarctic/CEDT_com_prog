#include<bits/stdc++.h>
using namespace std;

vector<pair<long long, string>> nums = {{1000000000000, "trillion"},
                                      {1000000000, "billion"},
                                      {1000000, "million"},
                                      {1000, "thousand"},
                                      {100, "hundred"},
                                      {90, "ninety"},
                                      {80, "eighty"},
                                      {70, "seventy"},
                                      {60, "sixty"},
                                      {50, "fifty"},
                                      {40, "forty"},
                                      {30, "thirty"},
                                      {20, "twenty"},
                                      {19, "nineteen"},
                                      {18, "eighteen"},
                                      {17, "seventeen"},
                                      {16, "sixteen"},
                                      {15, "fifteen"},
                                      {14, "fourteen"},
                                      {13, "thirteen"},
                                      {12, "twelve"},
                                      {11, "eleven"},
                                      {10, "ten"},
                                      {9, "nine"},
                                      {8, "eight"},
                                      {7, "seven"},
                                      {6, "six"},
                                      {5, "five"},
                                      {4, "four"},
                                      {3, "three"},
                                      {2, "two"},
                                      {1, "one"}};

string numberToWord(long long num)
{
    if (num == 0)
    {
        return "zero";
    }

    for (auto it : nums)
    {
        if (num >= it.first) 
        {
            return (num >= 100 ? numberToWord(num/it.first) + " " : "") + it.second + (num % it.first == 0 ? "" : " " + numberToWord(num % it.first));
        }
    }
    return "";
}

int main()
{
    long long n;
    cin >> n;
    string res = numberToWord(n);

    cout << res;

    return 0;
        
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