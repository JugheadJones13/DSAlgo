#include <bits/stdc++.h>
using namespace std;

long long findSol(priority_queue<long long>& a, priority_queue<long long>& b){
	long long ans = 0;
	while (!a.empty()){
		ans = ans + (a.top() * b.top());
		a.pop();
		b.pop();
	}
	return ans;
}

int main(){
	long long n;
	priority_queue<long long> a,b;
	cin >> n;
	long long temp;
	for (long long i = 0; i < n; i++){
		cin >> temp;
		a.push(temp);
	}
	for (long long i = 0; i < n; i++){
		cin >> temp;
		b.push(temp);
	}
	long long ans = findSol(a,b);
	cout << ans << endl;
}
