#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
using namespace std;

int main(){
	int n;
	cin >> n;
	int t1,t2;
	map<int,vector<int>> omap;
	for (int i = 1; i <= n; i++){
		cin >> t1 >> t2;	
		t1 = t1 + t2;
		auto it = omap.find(t1);
		if (it != omap.end()){
			it->second.push_back(i);
		}
		else{
			omap.insert({t1,{i}});
		}
	}

	for (auto x:omap){
		for (auto y:x.second){
			cout << y << " ";
		}
	}
	cout << '\n';
	return 0;
}

