#include <iostream>
using namespace std;

int fib_mem_save(int n){
	if (n <= 1) return n;
	int p,q;
	p = 0;
	q = 1;	
	int temp;
	for (int i = 2; i < n + 1; i++){
		temp = p + q;
		p = q;
		q = temp;
	}
	return q;
}

int main (){
	int n;
	cin >> n;
	cout << fib_mem_save(n) << endl;
	return 0;
}
