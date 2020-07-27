#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(),arr.end());
	int min = 100000000;
	for (int i = 0; i <= n-k; i++){
		int currmin =arr[i+k-1]-arr[i]; 
		if (currmin < min){
			min = currmin;
		} 
	}
	cout << min << endl;
	return 0;
}

