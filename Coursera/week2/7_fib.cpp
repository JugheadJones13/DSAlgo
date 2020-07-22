#include <iostream>
#include <vector>
using namespace std;

int solve(long long m, long long n){
	vector<int> seq = {0,1};
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
		else if (i > n) stop = 1;
		else seq.push_back(temp);	
		i++;
	}	
	long long size = seq.size();
	if (!done) 
		for (int j = m; j <= n; j++) 
			ans = (ans + seq.at(j)) % 10;
	else{
		long long q1 = m/size;
		long long q2 = n/size;
		if (q1 == q2){
			for (int j = m%size; j <= n%size; j++) 
				ans = (ans + seq.at(j)) % 10;
		}
		else{
			if (q2 - q1 == 1){
				for (int j = m%size; j < size; j++)
					ans = (ans+seq.at(j)) % 10;
				for (int j = 0; j <= n % size; j++)
					ans = (ans+seq.at(j)) % 10;
					
			}
			else{
				int total = 0;
				
				for (int j = m%size; j < size; j++)
					ans = (ans+seq.at(j)) % 10;
				for (int j = 0; j <= n % size; j++)
					ans = (ans+seq.at(j)) % 10;

				for (int j = 0; j < size; j++)
					total = (total+seq.at(j))%10;
				ans = (ans + (((q2 - q1) * total) % 10)) % 10;

			}
		}
	}
	return ans;
}

int main(){
	long long m,n;
	cin >> m >> n;
	cout << solve(m,n) << endl;
}
