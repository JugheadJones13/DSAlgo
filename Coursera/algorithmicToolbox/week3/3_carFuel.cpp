#include <bits/stdc++.h>
using namespace std;

int findSol(int d, int m, int n, vector<int>& stops){
	/*
	0 200 375 550 750 950
	0 + 400 --> 1
	375 + 400 --> 1
	750 + 400
	*/
	bool done = false;
	int index = 0;
	int fills = 0;
	int canGo;
	while (1){
		canGo = stops[index] + m;
		int i = index;
		while (stops[i] <= canGo && i < stops.size()) i++;
		if (i - 1 == index) return -1;
		else if (i-1 == stops.size()-1) return fills;
		else {
			fills++;
			index = i - 1;
		}
	}
	return -100;
}

int main(){
	int d,m,n;
	vector<int> stops;
	stops.push_back(0);

	cin >> d >> m >> n;
	int tempIn;
	for (int i = 0; i < n; i++){
		cin >> tempIn;
		stops.push_back(tempIn);
	}
	stops.push_back(d);

	int ans = findSol(d,m,n,stops);
	cout << ans << endl;
}
