#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> words;

bool solve()
{
    cin >> n;

    vector<string> l(4);
    for (int i = 0; i < 4; ++i)
    {
        cin >> l.at(i);
    }

    for (int a = 0; a < 4; ++a)
    {
        for (int b = 0; b < 4; ++b)
        {
            if (a == b)
                continue;

            for (int c = 0; c < 4; ++c)
            {
                if (c == a || c == b)
                    continue;

                for (int d = 0; d < 4; ++d)
                {
                    if (d == a || d == b || d == c)
                        continue;

                    for (char l1 : l[a])
                    {
                        string word(1, l1);
                        words.insert(word);

                        for (char l2 : l[b])
                        {
                            word += l2;
                            words.insert(word);

                            for (char l3 : l[c])
                            {
                                word += l3;
                                words.insert(word);

                                for (char l4 : l[d])
                                {
                                    word += l4;
                                    words.insert(word);
                                    word.pop_back();
                                }
                                word.pop_back();
                            }
                            word.pop_back();
                        }
                        word.pop_back();
                    }
                }
            }
        }
    }
}

int main()
{
    solve();

    for (int i = 0; i < n; ++i)
    {
        string input;
        cin >> input;
        cout << (words.count(input) ? "YES" : "NO") << endl;
    }
    return 0;
}