#include <bits/stdc++.h>

using namespace std;

long long solve_helper(long long n) {

  if (n / 10 == 0)
    return n;

  long long sum = 0;

  while (n != 0) {
    sum += n % 10;
    n /= 10;
  }

  return solve_helper(sum);
}

long long superDigit(string n, long long k) {

  long long sum = 0;

  for (int i = 0; i < n.length(); i++) {
    sum += (n[i] - '0');
  }

  sum *= k;

  return solve_helper(sum);
}

int main(int argc, char const *argv[]) {

  long long n, k;
	cin >> n >> k;
	cout << superDigit(n, k);
	
  return 0;
}

