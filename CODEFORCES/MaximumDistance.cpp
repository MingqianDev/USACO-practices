#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    int x[N];
    vector<pair<int, int>> point;
    for (int i = 0; i < N; ++i)
    {
        cin >> x[i];
    }
    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        point.push_back(make_pair(x[i], temp));
    }
    
    int maxDistance = -1;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            maxDistance = max(maxDistance, (point.at(j).first - point.at(i).first) * (point.at(j).first - point.at(i).first) + (point.at(j).second - point.at(i).second) * (point.at(j).second - point.at(i).second));
        }
    }
                //     "-fsanitize=undefined",
                // "-fsanitize=address",
    cout << maxDistance << endl;
    return 0;
}