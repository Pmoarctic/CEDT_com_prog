#include<bits/stdc++.h>
using namespace std;

int main()
{
    string month[13] = {" ","JAN", "FEB", "MAR", "APR", "MAY", "JUN", 
                        "JUL", "AUG", "SEP", "OCT", "NOV" , "DEC"};

    string str;
    cin >> str;

    string  date = "";
    date += str[0];
    date += str[1];

    int mon = (str[3]-'0')*10 + (str[4]-'0');
    //cout << date;

    int year = (str[6]-'0')*1000+(str[7]-'0')*100+(str[8]-'0')*10+(str[9]-'0');

    cout << month[mon] << " " << date << ", " << year-543;
}