#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(),arr.end());
	int rule = n / 2;
	int prevElem = 2e9;
	int count = -1;
	int ans = 0;
	for (int i = 0; i < n; i++){
		int currElem = arr[i];
		if (currElem == prevElem){
			count++;
		}
		else{
			if (count > rule){
				ans = 1;
				break;
			}
			else{
				count = 1;
				prevElem = currElem;
			}
		}
	}
	if (count > rule) ans = 1;
	cout << ans << '\n';
	return 0;
}

