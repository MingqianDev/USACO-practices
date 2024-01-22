// #include <bits/stdc++.h>
// using namespace std;

// struct Grass
// {
//     int amount, pos;
//     char type;
//     Grass() : amount(0) {};
// };



// struct Cow{
//     bool grass;
//     char type;
//     // int position;
//     Cow() : grass(false) {};
// };

// int main(){
//     int T;
//     cin >> T;
//     while(T--){
//         int N, K;
//         vector<Cow> cow;
//         vector<Grass> grass;
//         cin >> N >> K;
//         for (int i = 0; i < N; ++i)
//         {
//             cin >> cow.at(i).type;
//         }

//         for (int i = 0; i < N; ++i)
//         {
//             if(cow.at(i).grass == false) {
//                 if(i+K < N){
//                     for (int j = 0; j < K; ++j)
//                     {
//                         cow.at(i + j)
//                     }
                    
//                 }
//             }
//         }
        
        
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		int k;
		cin >> n >> k;
		string s;
		cin >> s;

		int patchG = -k - 1; // first patch location which does not cover cow 1
		int patchH = -k - 1; // first patch location which does not cover cow 1

		int cnt = 0;
		string ans(n, '.');

		for (int i = 0; i < n; i++) {
			if (s[i] == 'G' && i - patchG > k) {
				// the nearest G patch we placed does not cover cow i
				++cnt;
				if (i + k >= n) {
					patchG = i;
					if (ans[patchG] == 'H') { patchG--; }
				} else {
					patchG = i + k; // place the G patch k away
				}
				ans[patchG] = 'G';
			}
			if (s[i] == 'H' && i - patchH > k) {
				// the nearest H patch we placed does not cover cow i
				++cnt;
				if (i + k >= n) {
					patchH = i;
					if (ans[patchH] == 'G') { patchH--; }
				} else {
					patchH = i + k; // place the H patch k away
				}
				ans[patchH] = 'H';
			}
		}
		cout << cnt << endl << ans << endl;
	}
}