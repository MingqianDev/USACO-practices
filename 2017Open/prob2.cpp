#include <bits/stdc++.h>
using namespace std;

int result = 0;

int solution(int N, int M, vector<string> spots, vector<string> plain) {

    //上同下异
    for (int i = 0; i < M; ++i) {
        unordered_set<char> spotsSet;
        for (string s : spots) {
            spotsSet.insert(s.at(i));
        }

        bool possible = true;
        for (string s : plain) {
            if (spotsSet.find(s.at(i)) != spotsSet.end()) possible = false; 
        }

        if (possible) result++;
    }

    // for (int i = 0; i < M; ++i) {
    //     pair<char, bool> sameLetter = make_pair(plain.at(0).at(i), true);
    //     for (string s : plain) {
    //         if (s.at(i) != sameLetter.first) sameLetter.second = false;
    //     }

    //     bool diffLetter = true;
    //     if (sameLetter.second) {
    //         for (string s : spots) {
    //             if (s.at(i) == sameLetter.first) diffLetter = false;
    //         }
    //         if (diffLetter) {
    //             result++;
    //         }
    //     }
    // }

    return -1;

}

int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int N, M; fin >> N >> M;
    vector<string> spots(N), plain(N);
    for (string& input : spots) { fin >> input; }
    for (string& input : plain) { fin >> input; }

    solution(N, M, spots, plain);

    fout << result;

    return 0;
}