
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 07 01:27:35 AM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<pair<int,long long>> ftimes(n);
	for (int i = 0; i < n; i++) ftimes[i] = {i,0}; 
	int job;
	for (int i = 0; i < m; i++){
		cin >> job;
		//extract thread with lowest ftime and lowest index
		cout << ftimes[0].first << " " << ftimes[0].second << '\n';
		ftimes[0].second += job; 
		int curr = 0;
		while(1){
			int lc = (curr+1)*2-1;
			int rc = (curr+1)*2;
			int vic = curr;

			if (lc < n){
				if (ftimes[lc].second <= ftimes[vic].second){
					if (ftimes[lc].second == ftimes[vic].second){
						if (ftimes[lc].first < ftimes[vic].first){
							vic = lc;
						}
					}
					else{
						vic = lc;
					}
				}
			}

			if (rc < n){
				if (ftimes[rc].second <= ftimes[vic].second){
					if (ftimes[rc].second == ftimes[vic].second){
						if (ftimes[rc].first < ftimes[vic].first){
							vic = rc;
						}
					}
					else{
						vic = rc;
					}
				}
			}

			if (vic == curr) break;
			else{
				pair<int,long long> t1 = ftimes[curr];
				ftimes[curr] = ftimes[vic];
				ftimes[vic] = t1;
				curr = vic;
				continue;
			}

		}
		//compute ftime for curr job and insert in heap
	}
	return 0;
}

