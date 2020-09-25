
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Sep 25 05:35:48 PM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
	node(int x){
		key = x;
	}
	int key;
	vector<struct node*> childQ;
};

int maxht;

void findHt(struct node* root,int i){
	if (i > maxht) maxht = i;
	if (root->childQ.size() == 0){
		return;
	}	
	else{
		for (auto x:root->childQ){
			findHt(x,i+1);
		}
	}
}

int main(){
	int t = 1;
	while(t--){
		maxht = 0;
		int n;
		cin >> n;
		vector<int> parents(n);
		vector<struct node*> ndPointers(n,NULL);
		for (int i = 0; i < n; i++) {
			cin >> parents[i];
			ndPointers[i] = new struct node(i);
		}

		struct node* root;
		for (int i = 0; i < n; i++){
			if (parents[i] == -1){
				root = ndPointers[i];
			}
			else{
				struct node* curr = ndPointers[i];
				struct node* pt = ndPointers[parents[i]];
				pt->childQ.push_back(curr);
			}
		}

		findHt(root,0);
		cout << ++maxht << '\n';
	}
	return 0;
}

