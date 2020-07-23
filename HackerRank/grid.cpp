#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(vector<string>& given,int n,int m){
	if (given.size() == 1){
		cout << "YES" << endl;
		return;
	}
	for (int i = 0; i < m; i++){
		for (int j = 1; j < n ; j++){
			char a = given[j][i];
			char b = given[j-1][i];
			if (a < b){
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
	return;
}

int main(){
	int t,n;
	cin >> t;
	while (t){
		vector<string> given;
		string temp;
		cin >> n;
		int ls;
		for (int i = 0; i < n; i++){
			cin >> temp;
			ls = temp.size();
			sort(temp.begin(),temp.end());
			given.push_back(temp);
		}
		solve (given,n,ls);
		--t;
	}
	return 0;
}
