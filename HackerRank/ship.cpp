#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> wts(n);
	for (int i = 0; i<n; i++) cin >> wts[i];
	sort(wts.begin(),wts.end());
	int ans = 0;
	int t1;
	while (!wts.empty()){
		t1 = wts[0] + 4;
		int i;
		while (!wts.empty() && wts.front() <= t1)
			wts.erase(wts.begin());
		ans++;
	}
	cout << ans << endl;
}
