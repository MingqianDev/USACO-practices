#include <bits/stdc++.h>
using namespace std;

struct Candy{
    int top;
    int bottom;
    Candy() : bottom(0){};
};


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<long long> cow(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> cow.at(i);
    }
    for (int i = 0; i < m; ++i)
    {
        int candy[] {0,0};
        cin >> candy[1];
        for (int j = 0; j < n; ++j)
        {
            
            if(cow.at(j) >= candy[0] && cow.at(j) < candy[1]) {
                long long canEat = cow.at(j) - candy[0];
                cow.at(j) += canEat;
                candy[0] += canEat;
            }
            else if(cow.at(j) >= candy[1]) {
                cow.at(j) += candy[1] - candy[0];
                break; 
            }
        }
        
    }

    for (auto c : cow) {
        cout << c << '\n';
    }

    

    return 0;
}