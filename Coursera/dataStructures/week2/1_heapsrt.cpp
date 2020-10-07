
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 05 06:18:29 PM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<pair<int,int>> ans;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = n-1; i >= 0; i--){
		int curr = i;
		while(1){
			int lc = (curr+1)*2 - 1;
			int rc = (curr+1)*2;
			int t1 = curr;
			t1 = (lc < n) ? ((arr[lc] < arr[t1]) ? lc : t1) : t1;
			t1 = (rc < n) ? ((arr[rc] < arr[t1]) ? rc : t1) : t1;
			if (t1 == curr) break;
			else{
				//swap curr with t1
				ans.push_back(make_pair(curr,t1));
				int t2 = arr[curr];
				arr[curr] = arr[t1];
				arr[t1] = t2;
				curr = t1;
				continue;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto x:ans){
		cout << x.first << " " << x.second << '\n';
	}
	return 0;
}

