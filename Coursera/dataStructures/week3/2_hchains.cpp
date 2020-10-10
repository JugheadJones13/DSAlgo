
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 10 12:12:18 PM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
	string val;
	struct node* next = NULL;

	node(string ip):val(ip),next(NULL){}
};

int p = 1000000007;
int x = 263;

int fhash(string& ip,int& m){
	int n = ip.size();
	long long ans = 0;
	for (int i = 0; i < n; i++){
		long long val = (int)ip[i];
		val *= (long long)pow(x,i);
		val = val % p;
		ans += val;
	}
	ans = ans % p;
	ans = ans % m;
	return ans;
}

int main(){
	int m,n;
	cin >> m >> n;
	vector<struct node*> arr(m,NULL);
	while(n--){
		string cmd;
		cin >> cmd;
		if (cmd == "add"){
			string ip;
			cin >> ip;
			int buck = fhash(ip,m);
			bool pres = false;
			if (arr[buck] == NULL){
				arr[buck] = new struct node(ip);
			}
			else{
				struct node* curr = arr[buck];
				while(curr){
					if (curr->val == ip){
						pres = true;
						break;
					}
					else{
						curr = curr->next;
					}
				}
				if (!pres){
					struct node* t1 = new struct node(ip);
					t1->next = arr[buck];
					arr[buck] = t1;
				}
			}
		}
		else if (cmd == "del"){
			string ip;
			cin >> ip;
			int buck = fhash(ip,m);
			if (arr[buck]){
				if (arr[buck]->val == ip){
					struct node* t3 = arr[buck];
					arr[buck] = arr[buck]->next;
					free(t3);
				}
				else{
					struct node* curr = arr[buck];
					while(curr->next){
						if (curr->next->val == ip){
							struct node* t3 = curr->next;
							curr->next = curr->next->next;
							free(t3);
							break;
						}
						else{
							curr = curr->next;
						}
					}
				}
			}
		}
		else if (cmd == "find"){
			string ip;
			cin >> ip;
			int buck = fhash(ip,m);
			if (arr[buck]){
				struct node* curr = arr[buck];
				bool found = false;
				while(curr){
					if (curr->val == ip){
						found = true;
						cout << "yes" << '\n';
						break;
					}
					else curr = curr->next;
				}
				if (!found) cout << "no" << '\n';
			}
			else cout << "no" << '\n';
		}
		else{
			int idx;
			cin >> idx;
			struct node* curr = arr[idx];
			while(curr){
				cout << curr->val << " ";
				curr = curr->next;
			}
			cout << '\n';
		}
	}
	return 0;
}

