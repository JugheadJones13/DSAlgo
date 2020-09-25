
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: Coursera Quick Sort	
Date: 2020 Aug 05 11:38:01 PM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void qsort(vector<int>& ip,int l,int r){
	if (r <= l) return;
	int pivot = ip[r];
	int lt = l;
	int rt = r;
	while (lt < rt){
		while (ip[lt] < pivot) lt++;
		while (rt > -1 && ip[rt] >= pivot) rt--;
		if (lt < rt){
			int temp = ip[rt];
			ip[rt] = ip[lt];
			ip[lt] = temp;
		}
	}
	int temp = ip[r];
	ip[r] = ip[lt];
	ip[lt] = temp;
	qsort(ip,l,lt-1);
	qsort(ip,lt+1,r);
}

int main(){
	int n;
	cin >> n;
	vector<int> ip(n);
	for (int i = 0; i < n; i++) cin >> ip[i];
	qsort(ip,0,ip.size()-1);
	for (auto x:ip)
		cout << x << " ";
	cout << endl;
	return 0;
}

