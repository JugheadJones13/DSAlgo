#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q > 0){
		int n,k;
		cin >> n >> k;
		vector<int> a(n);
		vector<int> b(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end(),greater<int> ());
		bool stop = false;
		for (int i = 0; i < n && !stop; i++){
			if (a[i] + b[i] < k){
				cout << "NO" << '\n';
				stop = true;
			}
		}
		if (!stop)
		cout << "YES" << '\n';
		--q;
	}
	return 0;
}

