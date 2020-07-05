#include <bits/stdc++.h>
using namespace std;

int fib_ldigit_sum(int n){
	if (n <=1) return n;
	int curr_sum = 1;
	int p = 0;
	int q = 1;
	int temp;
	for (int i = 2; i < n + 1; i++){
		temp = (p + q) % 10;
		p = q;
		q = temp;
		curr_sum = (curr_sum + q) % 10;
	}
	return curr_sum;

}

unsigned long long fib_ldigit_sum_formula(unsigned long long n){
	if (n <=1) return n;
	unsigned long long temp;
	vector <unsigned long long> seq = {0,1};
	bool done = false;
	for (unsigned long long i = 2; i < n + 3; i++){
		temp = (seq[i-1] + seq[i-2]) % 10;
		if (temp == 1 && seq[i-1] == 0){
			seq.pop_back();
			done = true;
			break;
		}
		else
			seq.push_back(temp);
	}
	unsigned long long size = seq.size();
	unsigned long long ans;
	if (done){
		ans = (n+2) % size;
		ans = seq[ans];
	}
	else {
		ans = seq[n+2];
	}
	//note this below.
	//if you subtract 1 from 0 it has to be 9. Because you take carry.
	return (ans) ? ans-1: 9;
}

int main (){
	unsigned long long n;
	cin >> n;
	cout << fib_ldigit_sum_formula(n) << endl;
	return 0;
}




