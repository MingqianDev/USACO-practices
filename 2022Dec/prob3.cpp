#include <bits/stdc++.h>
using namespace std;

bool sameStr(string s){
	char prev = s.at(0);
	for (char a : s){
		if (a != prev){
			return false;
		}
		prev = a;
	}
	return true;
}

bool diffStr(string s){
	char prev = s.at(0);
	for (char a : s){
		if (a != prev){
			return true;
		}
		prev = a;
	}
	return false;	
}
 
int main() {
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<string> input(m);
		string output;
		vector<string> input2(m);
		int type4 = 0;

		for (int i = 0; i < m; ++i)
		{
			cin >> input.at(i) >> output.at(i);
		}

		bool isdiffoutput = diffStr(output);
		
		for(int i = 0; i < m; i++){ //竖变横
			for (int j = 0; j < n; ++j)
			{
				input.at(i).at(j) = input2.at(j).at(i);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			type4 += 
		}
		


		
		

	}
 
	return 0;
}