/*
ID: 1caokyl1
LANG: C++
TASK: ride
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    // char a = '@';
    // fout << (int)a - 64;
    string comet, group;
    fin >> comet >> group;

    int a = 1, b = 1;
    for (char temp : comet)
    {
        a *= (int)temp - 64;
    }
    for (char temp : group)
    {
        b *= int(temp) - 64;
    }

    if (a % 47 == b % 47)
    {
        fout << "GO" << endl;
    }
    else
    {
        fout << "STAY" << endl;
    }

    return 0;
}