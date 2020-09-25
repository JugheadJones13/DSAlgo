#include <bits/stdc++.h>
using namespace std;

int findChangeCount(int m){
	int ans = 0;
	ans = m / 10;
	int rem = m % 10;
	ans += (rem/5);
	rem = rem % 5;
	ans += rem;
	return ans;
}

int main(){
	int m;
	cin >> m;
	int ans = findChangeCount(m);
	cout << ans << endl;
}
