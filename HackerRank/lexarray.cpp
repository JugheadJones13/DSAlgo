#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pos[arr[i]-1] = i;
	}
	int i = 0;
	while (i < n && k > 0){
		if (arr[i] == n - i){
			++i;
			continue;
		}
		int temp = arr[i];
		int temp2 = arr[pos[n-i-1]];
		arr[i] = arr[pos[n-i-1]];
		int temp3 = pos[n-i-1];
		arr[pos[n-i-1]] = temp;	
		pos[temp2-1] = i;
		pos[temp-1] = temp3; 
		--k;
		++i;
	}
	for (auto x:arr) cout << x << " ";
	cout << '\n';
	return 0;
}

