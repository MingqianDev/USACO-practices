#include <bits/stdc++.h>
using namespace std;

struct MixingMilk
{
    int capacity;
    int mass;
};

int main()
{
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    vector<MixingMilk> milk(3);
    for (int i = 0; i < 3; ++i)
    {
        fin >> milk.at(i).capacity >> milk.at(i).mass;
    }

    for (int i = 0; i < 100; ++i)
    {
        int nextBukket = i % 3 == 2 ? 0 : i % 3 + 1;
        if (milk.at(i % 3).mass < (milk.at(nextBukket).capacity - milk.at(nextBukket).mass))
        {
            milk.at(nextBukket).mass += milk.at(i % 3).mass;
            milk.at(i % 3).mass = 0;
        } else {
            milk.at(i % 3).mass -= milk.at(nextBukket).capacity - milk.at(nextBukket).mass;
            milk.at(nextBukket).mass =  milk.at(nextBukket).capacity;
        }
    }

    for (auto a : milk){
        fout << a.mass << '\n';
    }
    

    return 0;
}