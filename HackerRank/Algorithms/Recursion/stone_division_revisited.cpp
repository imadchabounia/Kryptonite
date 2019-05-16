#include <bits/stdc++.h>

using namespace std;

vector<long long int> arr;
long long int l;
//long memo[100000000000]; too large , we'll use a hashmap (hashtable)

map<long long int, long long int> memo;

long long int solve_helper(long long int n){

  if(n == 1 || n == 0) return 0;

  if (memo[n]) {
    return memo[n];
  }

  long long int result = 0;

  for(int i = 0; i < l; i++){

    long long int count = 0;

    if(n%arr[i] == 0 && n != arr[i]){

      count += 1;
      long long int k = n / arr[i];
      count += k * solve_helper(arr[i]);
      result = max(result, count);

    }else{

      continue;

    }
    
  }
 
  memo[n] = result;

  return result;
}

long long int stoneDivision(long long int n, vector<long long int> s) {
  arr = s;
  l = arr.size();
  return solve_helper(n);
}

int main() {
  long long int n, m;
  int q;
  cin >> q;
  while (q--) {
    arr.clear();
    int sz = memo.size();
    memo.clear();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      long long int a;
      cin >> a;
      arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    cout << stoneDivision(n, arr) << endl;
    ;
  }
}
