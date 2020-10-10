
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 10 01:55:31 AM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	unordered_map<int,string> umap;
	while(n--){
		string cmd;
		cin >> cmd;
		if (cmd == "add"){
			int num;
			string name;
			cin >> num >> name;
			umap[num] = name;
		}
		else if (cmd == "find"){
			int num;
			cin >> num;
			if (umap.find(num) != umap.end()){
				cout << umap[num] << '\n';
			}
			else{
				cout << "not found" << '\n';
			}
		}
		else{
			int num;
			cin >> num;
			if (umap.find(num) != umap.end()){
				umap.erase(num);
			}
		}
	}
	return 0;
}

