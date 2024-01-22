#include <bits/stdc++.h>
using namespace std;

int N;
string cows;

long long calculate(long long left, long long right) {
    if(left == 0) return right - 1 > 0 ? right - 1 : 0;
    if(right == 0) return left - 1 > 0 ? left - 1 : 0;
    return 2 * right - 1 + (left - 1) * (right + 1);
}

long long checkFirst() {
    long long right = 0;
    if (cows[0] == 'H') {
        for (int i = 1; i < N && cows.at(i) == 'G'; ++i)
            right++;
    } else {
        for (int i = 1; i < N && cows.at(i) == 'H'; ++i)
            right++;
    }
    return right - 1 > 0 ? right - 1 : 0;
}

long long checkLast() {
    long long left = 0;
    if (cows.back() == 'H') {
        for (int i = N - 2; i >= 0 && cows.at(i) == 'G'; --i)
            left++;
    } else {
        for (int i = N - 2; i >= 0 && cows.at(i) == 'H'; --i)
            left++;
    }
    return left - 1 > 0 ? left - 1 : 0;
}

int main() {
    cin >> N;
    cin >> cows;

    long long result = 0;
    result += checkFirst();
    for (int i = 1; i < N - 1; ++i)
    {
        long long left = 0, right = 0;
        if (cows.at(i) == 'G') {
            for (int j = i+1; j < N && cows.at(j) == 'H'; ++j)
                right++;
            for (int j = i-1; j >= 0 && cows.at(j) == 'H'; --j)
                left++; 
        } else {
            for (int j = i+1; j < N && cows.at(j) == 'G'; ++j)
                right++;
            for (int j = i-1; j >= 0 && cows.at(j) == 'G'; --j)
                left++;
        }

        result += calculate(left, right);
    }
    result += checkLast();
    cout << result << '\n';

    return 0;
}