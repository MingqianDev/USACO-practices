#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int N, M; fin >> N >> M;
    vector<string> spots(N), plain(N);
    for (string &input : spots) {  fin >> input; }
    for (string &input : plain) {  fin >> input; }

    for (int i = 0; i < M; ++i)
    {
        char sameLetter = spots.at(0).at(i);
        for (string s : spots) {
            s.at(i)
        }
    }
    


    return 0;
}