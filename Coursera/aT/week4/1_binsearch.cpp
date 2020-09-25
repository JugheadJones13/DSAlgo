#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int n,k;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> k;
	vector<int> b(k);
	for (int i = 0; i < k; i++) cin >> b[i];
	int i = 0;
	while (i < k){
		int key = b[i];
		int low = 0;
		int high = a.size()-1;
		bool stop = false;
		int mid;
		while(high > low && !stop){
			mid = low + (high - low) / 2;
			if (a[mid] == key){
				stop = true;
			}
			else if (a[mid] > key){
				high = mid -1;
			}
			else{
				low = mid + 1;
			}
		}
		if (stop){
			cout << mid << " ";
		}
		else{
			if (high == low){
				if (a[high] == key)
					cout << high << " ";
				else cout << "-1" << " ";
			}
			else{
				cout << "-1" << " ";
			}

		}
		i++;
	}
	cout << '\n';
	return 0;
}

