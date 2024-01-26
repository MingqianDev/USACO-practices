#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");

    string points; fin >> points;
    vector<bool> cross(52, false);
    int answer = 0;

    for (int i = 0; i < 52; ++i) {
        if (cross.at(i)) continue;

        for (int j = i + 1; j < 52; ++j) {
            // if配对
            if (points.at(i) == points.at(j)) {
                cross.at(j) = true;
                break;
            }

            if (cross.at(j)) answer++;
        }

    }

    fout << answer;
    return 0;
}