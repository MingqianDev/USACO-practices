#include <bits/stdc++.h>
using namespace std;

int calAverage(int begin, int end, vector<int> p){
    int sum = 0, num = end - begin + 1;
    while(begin != end + 1) {
        sum += p.at(begin);
        begin++;
    }
    return sum % num == 0 ? sum / num : -1;
}

bool contain(int begin, int end, int target, vector<int> p) {
    while(begin != end + 1) {
        if (p.at(begin) == target) return true;
        begin++;
    }
    return false;
}

int main(){ 
    int N; cin >> N;
    vector<int> p(N);
    for(int &input : p) { cin >> input; }

    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            int avg = calAverage(i, j, p);
            if (avg != -1 && contain(i, j, avg, p)) result++; 
        }
    }
    
    cout << result << endl;

    return 0;
}