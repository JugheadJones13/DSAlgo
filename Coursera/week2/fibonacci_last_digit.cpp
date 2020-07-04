//to find last digit of fib number
#include <bits/stdc++.h>
using namespace std;

int lastDigFib (int n){
	int * table = new int[n];
	if (n <= 1) return n;
	table[0] = 0;
	table[1] = 1;
	for (int i = 2; i < n; i++){
		table[i] = (table[i-1] + table [i-2]) % 10;
	}
	return (table[n-1] + table [n-2]) % 10;
	
}

int main(){
	int ans = lastDigFib(327305);
	cout << ans << endl;
	return 0;
}
