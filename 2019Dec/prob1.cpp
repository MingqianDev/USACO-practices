// notice that "If A appears before B in one of these lines, that means cow A did better than cow B"
// the number of the input doesn't means the cow's score, the number of the input only means the cow's number

#include <bits/stdc++.h>
using namespace std;

int K, N;
int result = 0;


bool compare(int a, int b, vector<vector<int>> cows) {
    bool better = true;
    for (int session = 0; session < K; ++session) {
        int apos, bpos;
        for (int i = 0; i < N; ++i) {
            if (cows.at(session).at(i) == a) apos = i;
            if (cows.at(session).at(i) == b) bpos = i;
        }
        if (apos < bpos) better = false;
    }

    return better;

}

int main() {
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");

    fin >> K >> N;
    vector<vector<int>> cows(K, vector<int>(N));

    for (auto& row : cows) {
        for (int& input : row) {
            fin >> input;
        }
    }

    for (int a = 1; a <= N; ++a) {
        for (int b = 1; b <= N; ++b) {
            if (a == b) continue;
            if(compare(a,b,cows)) result++;
        }

    }

    fout << result;
    return 0;
}