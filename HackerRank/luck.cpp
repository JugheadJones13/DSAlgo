#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int a,b;
	int nImp = 0;
	int ans = 0;
	vector <int> valImps;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		if (b) {
			nImp++;
			valImps.push_back(a);	
		}
		ans += a;
	}
	int t1 = nImp - k;
	sort (valImps.begin(),valImps.end());
	//t1 wins required in valImps
	for (int i = 0; i < t1; i++){
		ans = ans - (2 * valImps[i]);
	}
	cout << ans << endl;
}
