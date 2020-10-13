
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 11 03:06:38 PM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans;
    void callR(string& s,int used){
				cout << used << endl;
        int n = s.length();
				if (s[used] == '0') return;
        if (used == n){
            ans++;
            return;
        }
        int touse = n - used;
        if (touse > 1){
            string numstr = s.substr(used,2);
            int curr = stoi(numstr);
            if (curr < 27){
                callR(s,used+2);
                if (s[used+1] != '0')
                callR(s,used+1);
            }
            else{
                callR(s,used+1);
            }
        }
        else{
            callR(s,used+1);
        }
    }
    int numDecodings(string s) {
        ans = 0;
        if (s[0] == '0') return ans;
        int n = s.length();
        for (int i = 1; i < n; i++){
            if (s[i] == '0' && (s[i-1] != '1' && s[i-1] != '2')){
                return ans;
            }
        }
        callR(s,0);
        return ans;
    }
};

int main(){
	Solution inst;
	int ans = inst.numDecodings("111111111111111111111111111111111111111111111");
	cout << ans << '\n';
	return 0;
}

