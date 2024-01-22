/*
ID: 1caokyl1
LANG: C++
TASK: transform
*/
#include <bits/stdc++.h>
using namespace std;

// vector<vector<char>> rotation_90(vector<vector<char>> pattern){

// };

// vector<vector<char>> rotation_180(vector<vector<char>> pattern){

// };

// vector<vector<char>> rotation_270(vector<vector<char>> pattern){

// };

// vector<vector<char>> reflection(vector<vector<char>> pattern){

// };




int main() {
    ifstream fin("transform.in");
    ofstream fout("transform.out");

    int N;
    fin >> N;
    string pattern[2*N];
    vector<char> square;
    for (int i = 0; i < 2*N; ++i)
    {
        fin >> pattern[i];  
    }

    for (string s : pattern) {
        for (char s2 : s) {
            
        }
    }
    

    return 0;
}