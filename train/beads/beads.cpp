/*
ID: 1caokyl1
LANG: C++
TASK: beads
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    int N, length = 0;
    string necklace;
    vector<char> neck;
    unordered_map<char, int> windowRight, windowLeft;
    fin >> N >> necklace;
    if (N == 0) {
        fout << 0 << endl;
    }
    if (N == 1) {
        fout << 1 << endl;
    }

    necklace += necklace;

    for (auto c : necklace) {
        neck.push_back(c);
    }

    int left, cut, right;
    right = -1;
    cut = -1;
    left = 0;
    while (right < (signed)neck.size() - 1)
    {
        right++;
        windowRight[neck[right]]++;

        while (windowRight['b'] != 0 && windowRight['r'] != 0) 
        {
            cut++;
            windowLeft[neck[cut]]++;
            windowRight[neck[cut]]--;
        }

        while(windowLeft['b'] != 0 && windowLeft['r'] != 0){
            windowLeft[neck[left]]--;
            left++;
        }

        length = max(length, right - left + 1);
    }

    if (length > N)
        length = N;

    fout << length << endl;

    return 0;
}