
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Sep 25 02:16:45 PM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

bool isClosing(char a){
	return (a == '}') || (a == ']') || a == ')';
}


int main(){
	int t = 1;
	//cin >> t;
	while(t--){
		string s;
		bool stop = false;
		cin >> s;
		int n = s.length();
		stack<int> stk;
		int ans = -1;
		if (s[0] == '(' || s[0] == ')' || s[0] == '[' || s[0] == ']' || s[0] == '{' || s[0] == '}' ){
			if (isClosing(s[0])){
				ans = 0;
				stop = true;
			}
			stk.push(0);
		}
			
		for (int i = 1; i < n && !stop; i++){
			if (stk.size() && ((s[i] == '}' && s[stk.top()] == '{') || (s[i] == ')' && s[stk.top()] == '(') || (s[i] == ']' && s[stk.top()] == '['))){
				stk.pop();
				continue;
			}
			if (s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']' && s[i] != '{' && s[i] != '}' ) continue;
			if (stk.size()){
				if (isClosing(s[i])){
					ans = i;
					break;
				}
				else{
					stk.push(i);
				}
			}
			else{
				if (isClosing(s[i])){
					ans = i;
					break;
				}
				else{
					stk.push(i);
				}
			}
		}
		
		if (ans == -1){
			if (stk.size())
				ans = stk.top();
		}
		
		if (ans == -1) cout << "Success\n";
		else cout << ans+1 << '\n';
		//ans
	}
	return 0;
}

