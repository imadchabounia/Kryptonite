#include <bits\stdc++.h>

using namespace std;

vector<int> memo;

void memo_init(){
  for(int i = 0; i < 41; i++){
    memo.push_back(0);
  }
}

int solve(int n){

  if(n < 4) return 1;
  else if(n == 4) return 2;

  if(memo[n] == 0){

    memo[n] = solve(n-1) + solve(n-4);

  }

  return memo[n];
}

bool is_prime(int n){

  for(int i = 2; i <= sqrt(n); i++){

      if(n % i == 0) return false;
  }


  return true;

}

int get_primes(int n){

  int count = 0;

  for(int i = 2; i <= n; i++){
    if(is_prime(i)) count++;
  }


  return count;

}

int redJohn(int n) {

  int num_ways = solve(n);
  return get_primes(num_ways);

}

int main(int argc, char const *argv[]) {

  int n;
  memo_init();
  cin >> n;
  cout << "solution : " << redJohn(n);
  return 0;
}
