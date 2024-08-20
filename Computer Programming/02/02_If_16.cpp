#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << ((n>0)?"positive\n":(n<0)?"negative\n":"zero\n");
    cout << ((n%2)?"odd":"even");
}