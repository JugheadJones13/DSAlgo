
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Sep 26 01:19:35 AM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t = 1;
	//cin >> t;
	while(t--){
		int s,n;
		cin >> s >> n;
		if (n != 0){
			int a,b;
			queue<int> ftimes;
			for (int i = 0; i < n; i++){
				cin >> a >> b;	
				while(!ftimes.empty() && ftimes.front() <= a){
					ftimes.pop();
				}
				if (ftimes.size() == s){
					//buffer full
					cout << "-1" << '\n';
				}
				else{
					if (ftimes.empty()){
						cout << a << '\n';
						ftimes.push(a+b);
					}
					else{
						cout << ftimes.back() << '\n';
						ftimes.push(ftimes.back() + b);
					}
				}
			}
		}
	}
	return 0;
}

/*
//version 1
bool canTake(queue<int>& buffer,int size){
	return (buffer.size() < size);
}

int main(){
	int t = 1;
	while(t--){
		bool done = false;
		int s,n;
		int a,b;
		cin >> s >> n;
		if (n != 0){
			vector<pair<int,int>> info(n);
			vector<int> output(n,-1);
			for (int i = 0; i < n; i++){
				cin >> a >> b;
				info[i] = make_pair(a,b);
			}

			int time = 0;
			int freeTime = 0;
			queue<int> buffer;
			int currPkt = 0;
			bool dproc = false;
			queue<int> poptimes;
			while (1){
				if (currPkt == n) dproc = true;
				
				if (!poptimes.empty() && poptimes.front() == time){
					buffer.pop();
					poptimes.pop();
				}
				
				if (buffer.empty() && time >= freeTime){
					if (currPkt < n && info[currPkt].first == time && info[currPkt].second == 0){
						output[currPkt] = time;
						currPkt++;	
						continue;
					}
				}

				while(currPkt < n && info[currPkt].first == time){
					if (info[currPkt].first == time){
						if (canTake(buffer,s)){
							buffer.push(currPkt);
						}
						currPkt++;
					}
				}

				if (time >= freeTime){
					//proc currently free
					if (!buffer.empty()){
						int qtop = buffer.front();
						freeTime = time + info[qtop].second;
						poptimes.push(freeTime);
						//buffer.pop();
						output[qtop] = time;
						if (qtop == n-1) break;
					}
					else{
						if (dproc) break;
					}
				}	
				++time;
			}

			for (auto x:output) cout << x << '\n';
		}
	}
	return 0;
}
*/
