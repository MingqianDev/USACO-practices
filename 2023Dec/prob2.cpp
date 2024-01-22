#include <bits/stdc++.h>
using namespace std;

bool allEqualOne(string cow){
    for (char a : cow) {
        if (a == '0') return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n; cin >> n;
    string cow; cin >> cow;

    if (allEqualOne(cow)) {
       cout << '1' << '\n'; 
       return 0;
    } 

    int smallestBlock = INT_MAX;
    int start;
    int sick = 0;
    double result = 0;
    vector<int> block;
    if(cow.at(0) == '1'){
        sick++;
        start = 0;
    }
    for (int i = 1; i < n; ++i)
    {
        if(cow.at(i)=='1') sick++;
        if (cow.at(i) == '1' && cow.at(i - 1) == '0') start = i;
        if (cow.at(i) == '0' && cow.at(i - 1) != '0') {
            smallestBlock = min(smallestBlock, i - start);
            block.push_back(i - start);
        }
    }
    if(cow.at(n - 1) == '1'){
        smallestBlock = min(smallestBlock, n - start);
        block.push_back(n - start);
    }
    int source = smallestBlock % 2 == 0 ? 2 : 1;
    for (int a : block) {
        if (a % smallestBlock == 0) {
            result += (a / smallestBlock) * source;
        } else {
            result += (a / smallestBlock) * source + 1;
        }
    }
    
    cout << result << '\n';

    return 0;
}