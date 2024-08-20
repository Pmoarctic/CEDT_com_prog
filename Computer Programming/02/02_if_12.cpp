#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    double n;
    cin >> n;

    char grade = (n>=80&&n<=100)*'A'+(n>=70&&n<80)*'B'+(n>=60&&n<70)*'C'+(n>=50&&n<60)*'D'+(n<50)*'F';
    cout << grade;
}