
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Sep 27 01:55:20 AM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t = 1;
	//cin >> t;
	while(t--){
		int q;
		cin >> q;
		stack<int> maxlog;
		string cmd;
		while (q--){
			cin >> cmd;
			if (cmd == "push"){
				int t1;
				cin >> t1;
				if (maxlog.empty()) maxlog.push(t1);
				else{
					if (maxlog.top() >= t1){
						maxlog.push(maxlog.top());
					}
					else{
						maxlog.push(t1);
					}
				}
			}
			else if (cmd == "pop"){
				maxlog.pop();
			}
			else{
				cout << maxlog.top() << '\n';
			}
		}
	}
	return 0;
}

