#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> A,B;
	int ans = 0;
	int temp;
	for (int i = 0; i < n; i++){
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < n; i++){
		cin >> temp;
		auto it = find(A.begin(),A.end(),temp);
		if (it != A.end()){
			A.erase(it);
			ans++;
		}
		else{
			B.push_back(temp);
		}
	}
	ans = (A.size() ? (ans + 1): ans -1);
	cout << ans << endl;
	return 0;
}
