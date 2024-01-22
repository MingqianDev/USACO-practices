#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);


    int n;
    cin >> n;
    string cow;
    vector<int> e(n + 1);
    cin >> cow;
    for (int i = 1; i <= n; i++)
    {
        cin >> e.at(i);
    }

    int Gfirst = 0, Glast = 0, Hfirst = 0, Hlast = 0;
    int GPossLeader = 0, HPossLeader = 0;
    for (int i = 0; i < n; i++) {
        if (Gfirst == 0 && cow.at(i) == 'G'){
            Gfirst = i + 1;
        }
        if (Hfirst == 0 && cow.at(i) == 'H'){
            Hfirst = i + 1;
        }
        if (cow.at(i) == 'G'){
            Glast = i + 1;
        } else {
            Hlast = i + 1 ;
        }
    }

    if (e.at(Gfirst) >= Glast) {
        GPossLeader++;
        for (int i = 0; i < Gfirst; ++i)
        {
            if (cow.at(i) == 'H' && e.at(i+1) >= Gfirst) HPossLeader++;
        }
    }
    if (e.at(Hfirst) >= Hlast) {
        HPossLeader++;
        for (int i = 0; i < Hfirst; ++i)
        {
            if (cow.at(i) == 'G' && e.at(i+1) >= Hfirst) GPossLeader++;
        }
    }
    
    cout << GPossLeader * HPossLeader << '\n';


    return 0;
}