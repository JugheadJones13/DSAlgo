#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if (a == 0 || b == 0){
		if (b == 0) return a;
		else return b;
	}
	bool run = true;
	int rem;
	while (run){
		if (a > b) rem = a % b;
		else rem = b % a;
		if (rem == 1 || rem == 0) run = false;
		else{
			if (a > b) a = rem;
			else b = rem;
		}
	}
	if (rem == 1) return 1;
	else{
		if (a > b) return b;
		else return a;
	}
	return 123123;
}

int main(){
	int a,b;
	cin >> a >> b;
	cout << gcd (a,b) << endl;
	return 0;
}
