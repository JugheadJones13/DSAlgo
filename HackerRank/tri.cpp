#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>& sticks, int& n){
	int idx = n -1;
	while (idx >= 2){
		if (sticks[idx] < (sticks[idx-1] + sticks[idx -2])){
			cout << sticks[idx-2] << " " << sticks[idx-1] << " " << sticks[idx] << endl;
			return;
		}
		else --idx; 
	}
	cout << "-1" << endl;
	return;
}

int main(){
	int n;
	cin >> n;
	vector<int> sticks;
	int temp;
	for (int i = 0; i < n; i++){
		cin >> temp;
		sticks.push_back(temp);	
	}
	sort (sticks.begin(),sticks.end());
	solve (sticks,n);
}
