
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 08 04:21:29 PM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& djs,int i){
	if (djs[i] != i){
		djs[i] = find(djs,djs[i]);
	}
	else{
		return i; 
	}
	return djs[i];
}

int main(){
	int n,m;
	cin >> n >> m;
	int max = -1;
	vector<int> arr(n);
	vector<int> djs(n);
	vector<int> ranks(n,0);
	for (int i = 0; i < n; i++){
		int t1;
		cin >> t1;
		if (t1 > max) max = t1;
		arr[i] = t1;
		djs[i] = i;
	}
	while(m--){
		int d,s;
		cin >> d >> s;	
		--d;
		--s;
		int idd = find(djs,d);
		int ids = find(djs,s);
		if (idd == ids){
			cout << max << '\n';
			continue;
		}
		else{
			if (ranks[idd] == ranks[ids]){
				djs[idd] = ids;
				ranks[ids]++;
				arr[ids] += arr[idd];
				if (arr[ids] > max) max = arr[ids];
				cout << max << '\n';
				continue;
			}		
			else if (ranks[idd] > ranks[ids]){
				djs[ids] = idd;
				arr[idd] += arr[ids];
				if (arr[idd] > max) max = arr[idd];
				cout << max << '\n';
				continue;
			}
			else{
				djs[idd] = ids;
				arr[ids] += arr[idd];
				if (arr[ids] > max) max = arr[ids];
				cout << max << '\n';
				continue;
			}
		}
	}
	return 0;
}

