
#include <bits\stdc++.h>

using namespace std;

int sum = 0;

int super_digit(int x){
	
	if(x/10 == 0){
		
		return x;
	
	}else{
		
	return super_digit(x%10+super_digit(x/10));

	
	}
	
}
// using loop
int solve_super_digit(int p, int k){
	
	for(long long i = 0; i < k; i++){
		
		sum += super_digit(p);
		
	}
	
	sum = super_digit(sum);
	
	return sum;
}

// Recursively 
int solve_super_digit2(int p, int k){
	
	if(k <= 0){
		
		return 0;
		
	}
	
	return super_digit(p) + solve_super_digit2(super_digit(p), k-1);
}

int main(){
	// simple test cases
	int p = 9875;
	int k = 4;
	
	cout << solve_super_digit2(p, k);

}
