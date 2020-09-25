#include <iostream>
#include <vector>
using namespace std;

int solve(long long n){
	//Fn == breadth | Fn+1 == length
	vector <int> seq = {0,1};
	int ans = 0;
	bool stop = 0;
	bool done = 0;
	int temp;
	long long i = 2;
	while (!stop){
		temp = (seq.at(seq.size()-1) + seq.at(seq.size()-2)) % 10;
		if (temp == 0 && temp+seq.at(seq.size()-1) == 1) {
			stop = 1;
			done = 1;
		}
		else if (i > n + 1) stop = 1;
		else seq.push_back(temp);	
		i++;
	}	
	long long size = seq.size();
	if (!done){
		ans = (seq.at(n) * seq.at(n+1))%10;
	}
	else{
		ans = (seq.at(n % size) * seq.at((n+1)%size)) % 10;
	}
	return ans;
}

int main(){
	long long n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
