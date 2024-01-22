/*
ID: 1caokyl1
LANG: C++
TASK: milk2
*/
#include <bits/stdc++.h>
using namespace std;

struct Milk
{
    int begain, end;
};

bool compare(Milk a, Milk b)
{
    return a.begain < b.begain;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ifstream fin("milk2.in");
    fin.tie(0);
    ofstream fout("milk2.out");

    int N;
    fin >> N;
    Milk milk[N];

    for (int i = 0; i < N; ++i)
    {
        fin >> milk[i].begain >> milk[i].end;
    }

    sort(milk, milk + N, compare);

    int currentBegain, currentEnd, spare = 0, continuousTime;
    currentBegain = milk[0].begain;
    currentEnd = milk[0].end;
    continuousTime = currentEnd - currentBegain;

    for (int i = 0; i < N; ++i)
    {
        if (milk[i].begain <= currentEnd && milk[i].end > currentEnd)
        {
            currentEnd = milk[i].end;
            continuousTime = max(continuousTime, currentEnd - currentBegain);
        }
        if (milk[i].begain > currentEnd)
        {
            spare = max(spare, milk[i].begain - currentEnd);
            currentBegain = milk[i].begain;
            currentEnd = milk[i].end;
            continuousTime = max(continuousTime, currentEnd - currentBegain);
        }
    }
    fout << continuousTime << " " << spare << endl;

    return 0;
}