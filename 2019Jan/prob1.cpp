#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    ifstream fin("shell.in");
    ofstream fout("shell.out");

    int N;
    fin >> N;

    unordered_map<char, int> counter;
    int result = 0;
    char shell[4] = {'z', 'a', 'b', 'c'};

    while(N--){
        int a, b, g;
        fin >> a >> b >> g;
        swap(shell[a], shell[b]);
        counter[shell[g]]++;
    }

    for (auto a : counter){
        result = max(result, a.second);
    }
    fout << result << '\n';

    return 0;
}