
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 15 02:58:27 AM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	string p,t;
	cin >> p >> t;
	int hp = 0;
	int np = p.length();
	int nt = t.length();
	for (int i = 0; i < np; i++){
		hp += (int)p[i];
	}
	if (np > nt) return 0;
	int curr = 0;
	for (int i = 0; i <= nt - np; i++){
		if (i == 0){
			for (int j = 0; j < np; j++){
				curr += (int)t[j];
			}
			if (curr == hp){
				bool found = true;
				for (int j = 0; j < np; j++){
					if (t[j] != p[j]){
						found = false;
						break;
					}
				}
				if (found) cout << i << " ";
			}
		}
		else{
			curr -= (int)t[i-1];
			curr += (int)t[i+np-1];
			if (curr == hp){
				bool found = true;
				for (int j = 0; j < np; j++){
					if (t[i+j] != p[j]){
						found = false;
						break;
					}
				}
				if (found) cout << i << " ";
			}
		}
	}
	cout << endl;
	return 0;
}

