/*
ID: 1caokyl1
LANG: C++
TASK: gift1
*/
#include <bits/stdc++.h>
using namespace std;

struct account{
    string name;
    int money;
};

int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    int NP;
    fin >> NP;

    // account personData[NP];
    unordered_map<string, int> person; 

    list<string> list;

    for (int i = 0; i < NP; ++i)
    {
        string tempName;
        fin >> tempName;
        person[tempName] = 0;
        list.push_back(tempName);
    }
    
    for (int i = 0; i < NP; ++i)
    {
        string n;
        int money, NG;
        fin >> n >> money >> NG;

        for (int j = 0; j < NG; ++j)
        {
            string receive;
            fin >> receive;
            person[receive] += money / NG;
            person[n] -= money / NG;
        }

        
    }
    
    for (const auto& name : list) {
        fout << name << " " << person[name] << endl;
    }
    return 0;
}
