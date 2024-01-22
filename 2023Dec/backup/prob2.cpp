#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    int n; cin >> n;
    string cow; cin >> cow;

    double num = 0;
    int block = 0, sick = 0;
    int smallestNight = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        if (cow.at(i) == '1') {
            num++;
            sick++;
        } else if (num != 0){
            smallestNight = min(smallestNight, (int)ceil(num / 2) - 1);
            block++;
            num = 0;
        }
    }
    if(num != 0){
       smallestNight = min(smallestNight, (int)ceil(num / 2) - 1); 
       block++;
    } 
    
    cout << sick - (block * smallestNight * 2);
    

    return 0;
}