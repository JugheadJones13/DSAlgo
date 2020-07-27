#include <iostream>
#include <vector>
using namespace std;


int solve(vector<int>& stu,vector<int>& ans,int& n){
}

int main(){
	int n;
	cin >> n;
	vector<int> stu;
	vector<int> ans(n,1);
	int temp;
	for (int i = 0; i < n; i++){
		cin >> temp;
		stu.push_back(temp);
	}
	cout << solve(stu,ans,n) << endl;
}
