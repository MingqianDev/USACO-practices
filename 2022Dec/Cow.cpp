#include <bits/stdc++.h>
using namespace std;

bool compare(long long a, long long b)
{
    return a > b;
}

struct a
{
    long long num;
    int charge;
};

a method1(int N, long long c[])
{
    a maxi;
    maxi.num = 0;
    maxi.charge = INT_MAX;
    // sort(c[0], c[N - 1], compare);
    for (int i = 0; i < N; ++i)
    {
        a temp;
        temp.num = 0;
        temp.charge = 0;
        for (int j = 0; j < N; ++j)
        {
            if (c[j] >= c[i])
            {
                temp.num += c[i];
                temp.charge = c[i];
            }
        }
        if (temp.num >= maxi.num)
        {
            if (temp.num == maxi.num)
            {
                maxi.charge = min(temp.charge, maxi.charge);
            }
            else
            {
                maxi = temp;
            }
        }
    }
    return maxi;
}

a method2(int N, long long c[])
{
    a maxi;
    maxi.num = 0;
    maxi.charge = INT_MAX;
    sort(c, c + N, compare);

    for (int i = 0; i < N; ++i)
    {
        a temp;
        temp.num = 0;
        temp.charge = 0;
        for (int j = 0; c[j] >= c[i] && j < N; ++j)
        {
            temp.num += c[i];
            temp.charge = c[i];
        }

        if (temp.num >= maxi.num)
        {
            if (temp.num == maxi.num)
            {
                maxi.charge = min(temp.charge, maxi.charge);
            }
            else
            {
                maxi = temp;
            }
        }
    }
    return maxi;
}

a method3(int N, long long c[])
{
    sort(c, c + N);
    a result;
    result.charge = INT_MAX;
    result.num = 0;
    for (int i = 0; i < N; ++i)
    {
        if (c[i] * (N-i) >= result.num){
            if (c[i] * (N-i) == result.num) {
                result.charge = min(result.charge, (int)c[i]);
            } else {
                result.num = c[i] * (N-i);
                result.charge = c[i];
            }
        } 
    }
    return result;
}

int main()
{
    // ifstream fin("prob1_bronze_dec22/12.in");
    int N;
    cin >> N;
    long long c[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> c[i];
    }

    // a stand = method1(N, c);
    a result = method3(N, c);

    // cout << stand.num << " " << stand.charge << endl;
    cout << result.num << " " << result.charge << endl;

    return 0;
}