
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 10 11:22:14 AM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        int N = nums.size();
        for(int n = N; n > 0; n--){
            for (int k = n-1; k >= 0; k--){
                int i = k;
                while(1){
                    int lc = (i+1)*2-1;
                    int rc = (i+1)*2;
                    if (lc >= n && rc >= n){
                        break;
                    }
                    else{
                        if (rc >= n){
                            //only lc
                            if (nums[lc] > nums[i]){
                                int t1 = nums[i];
                                nums[i] = nums[lc];
                                nums[lc] = t1;
                                i = lc;
                                continue;
                            }
                            else break;
                        }
                        else{
                            //both
                            int big = i;
                            big = (nums[lc] > nums[big]) ? lc : big;
                            big = (nums[rc] > nums[big]) ? rc : big;
                            if (big == i) break;
                            else{
                                if (nums[lc] > nums[rc]){
                                    int t1 = nums[i];
                                    nums[i] = nums[lc];
                                    nums[lc] = t1;
                                    i = lc;
                                    continue;
                                }
                                else{
                                    int t1 = nums[i];
                                    nums[i] = nums[rc];
                                    nums[rc] = t1;
                                    i = rc;
                                    continue;
                                }
                            }
                        }
                    }
                    

                }
            }
            int t2 = nums[0];
            nums[0] = nums[n-1];
            nums[n-1] = t2;
        }
        return;
        
    }

int main(){
	vector<int> nums = {2,0,2,1,1,0};	
	sortColors(nums);
	for (auto x:nums) cout << x << " ";
	cout << '\n';
	return 0;
}

