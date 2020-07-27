#include <iostream>
#include <assert.h>
using namespace std;


string solve(int n){
	if (n < 3) return "-1";
	string ans = "";
	if (n % 3 == 0){
		for (int i = 0; i < n; i++) ans += "5";
	}
	else if (n % 3 == 1){
		if (n - 10 < 0){
			ans = "-1";
		}
		else{
			int t1 = n - 10;
			for (int i = 0; i < n; i++){
				if (i < t1) ans += "5";
				else ans += "3";
			}
		}
	}
	else{
		assert(n % 3 == 2);
		if (n - 5 < 0){
			ans = "-1";
		}
		else{
			int t2 = n - 5;
			for (int i = 0; i < n; i++){
				if (i < t2) ans += "5";
				else ans += "3";
			}
		}
	}
	return (ans);
}


int main(){
	int t,n;
	cin >> t;
	while (t > 0){
		cin >> n;
		cout << solve(n) << endl;	
		--t;
	}
	return 0;
}
