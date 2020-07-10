#include <bits/stdc++.h>
using namespace std;

double findSol(map<double,double>& table,double w){
	double ans = 0;
	while (w > 0){
		if (table.size() == 0) return ans;
		if (table.rbegin()->second >= w){
			ans = ans + table.rbegin()->first * (double)w;
			w = w - table.rbegin()->second;
		}
		else {
			ans = ans + table.rbegin()->first * (double) table.rbegin()->second;
			w = w - table.rbegin()->second;
			table.erase(--table.end());
		}
	}
	return ans;	
}

int main(){
	double n,w;
	cin >> n >> w;
	map<double,double> table; //[valueperunitweight --- totalQuantity]
	double a;
	double b;
	double pu;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		pu = a / b;
		table[pu] = b;
	}

	double ans = findSol(table,w);
	cout << fixed << setprecision(4) << ans << endl;

}
