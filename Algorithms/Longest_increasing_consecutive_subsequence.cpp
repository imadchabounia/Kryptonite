#include<bits/stdc++.h>

using namespace std;

/*
longest consecutive increasing sequence in an array
input : [100, 4, 200, 1, 3, 2]
*/

// DP Based Solution

int LCS(vector<int> arr){

  int ans = INT_MIN;

  int DP[10000];
  int n = arr.size();

  memset(DP, 0, n);

  for(int i = 0; i <= n; i++){
    DP[i] = 1;

    for(int j = i-1; j >= 0; j--){
      if(arr[i]-arr[j] == 1){
        DP[i] += DP[j];
        ans = max(ans, DP[i]);
        break;
      }
    }
  }

  return ans;
}

int main(int argc, char const *argv[]) {

  vector<int> arr = {100, 4, 200, 1, 3, 2, 5, 6, 121, 7, 8};
  cout << "Longest Consecutive sequence is : " << LCS(arr) << endl;

  return 0;
}
