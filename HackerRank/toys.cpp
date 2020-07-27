#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> toys(n);
	for (int i = 0; i < n; i++) cin >> toys[i];
	sort(toys.begin(),toys.end());
	int sum = 0;
	int i = 0;
	int ans = 0;
	while (sum <= k && i < n){
		sum += toys[i];
		if (sum <= k)
		++ans;
		++i;
	}
	cout << ans << endl;
	return 0;
}

