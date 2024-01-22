#include <bits/stdc++.h>
using namespace std;

bool allEqual(vector<int> v) { 
  int first = v.at(0);
  for (auto i : v) {
    if (i != first) {
      return false;
    }
  }
  return true;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> sleepTime(N, 0);
        for (int i = 0; i < N; ++i)
        {
            cin >> sleepTime.at(i);
        }
        sort(sleepTime.begin(), sleepTime.end());

        while(!allEqual(sleepTime)){
            auto largest = max_element(sleepTime.begin(), sleepTime.end());
            
        }

    }



    return 0;
}