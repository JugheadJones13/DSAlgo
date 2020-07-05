#include <bits/stdc++.h>
using namespace std;

int fib_mod_m(unsigned long long n,unsigned long long m){
	//find fib(n) mod m;
	if (n <= 1) return n;
	vector<unsigned long long> seq = {0,1};
	//dont actually have to have this fib vector
	//see fib_ldigit_sum.cpp file in current directory
	vector<unsigned long long> fib = {0,1};
	bool done = false;
	for (int i = 2; i < n +1; i++){
		//why is putting % m working below?
		fib.push_back((fib[i-1] + fib[i-2]) % m);
		if (fib[i] % m == 1 && seq[i-1] == 0) {
			done = true;
			seq.pop_back();
			break;
		}
		seq.push_back(fib[i] % m);
	}
	int a;
	if (done){
		int size = seq.size();
		a = n % size;
	}
	else {
		a = n;
	}
	return seq[a];
}

int main(){
	unsigned long long a,b;
	cin >> a >> b;
	cout << fib_mod_m(a,b) << endl;
	return 0;
}
