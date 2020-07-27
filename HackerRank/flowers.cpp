#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> cost(n);
	for (int i = 0; i < n; i++) cin >> cost[i];
	sort(cost.begin(),cost.end());
	int ans = 0;
	int factor = 1;
	if (k >= n){
		for (auto x:cost) ans += x; 
	}
	else{
		while (!cost.empty()){
			int start = cost.size()-1;
			for (int i = start; i > start - k && !cost.empty(); --i){
				ans += factor * cost[i];
				cost.pop_back();
			}
			factor = factor + 1;
		}
	}
	cout << ans << endl;
	return 0;
}

