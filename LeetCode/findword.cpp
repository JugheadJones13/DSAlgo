
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 11 11:01:09 AM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    string word;
    //from: left-0,right-1,bottom-2,top-3
    bool callR(vector<vector<char>>& board,int filled,int dir,int x,int y,vector<pair<int,int>> seen){
        if (ofb(x,y)) return false;
        if (filled == word.length()) return true;
        if (word[filled] != board[x][y]) return false;
        auto it = find(seen.begin(),seen.end(),make_pair(x,y));
        if (it != seen.end()) return false;
        filled++;
        bool ans = false;
        seen.push_back(make_pair(x,y));
        int i = x;
        int j = y;
        if (dir == 0){
            ans = callR(board,filled,0,i,j+1,seen);
            if (ans) return ans;
            ans = callR(board,filled,2,i-1,j,seen);
            if (ans) return ans;
            ans = callR(board,filled,3,i+1,j,seen);
            if (ans) return ans;
        }
        else if (dir == 1){
            ans = callR(board,filled,1,i,j-1,seen);
            if (ans) return ans;
            ans = callR(board,filled,2,i-1,j,seen);
            if (ans) return ans;
            ans = callR(board,filled,3,i+1,j,seen);
            if (ans) return ans;
        }
        else if (dir == 2){
            ans = callR(board,filled,2,i-1,j,seen);
            if (ans) return ans;
            ans = callR(board,filled,1,i,j-1,seen);
            if (ans) return ans;
            ans = callR(board,filled,0,i,j+1,seen);
            if (ans) return ans;
        }
        else if (dir == 3){
            ans = callR(board,filled,3,i+1,j,seen);
            if (ans) return ans;
            ans = callR(board,filled,1,i,j-1,seen);
            if (ans) return ans;
            ans = callR(board,filled,0,i,j+1,seen);
            if (ans) return ans;
        }
        else{
            assert(0);
        }
        return ans;
    }
    bool ofb(int i,int j){
        bool ans = (i >= m || j >= n || i < 0 || j < 0);
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word1) {
        m = board.size();
        n = board[0].size();
        word = word1;
        bool ans = false;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (word[0] == board[i][j]){
                    //(i-1,j),(i+1,j),(i,j-1),(i,j+1)
                    vector <pair<int,int>> t1;
                    t1.push_back(make_pair(i,j));
                    if (word.length() == 1) return true;
                    ans = callR(board,1,1,i,j-1,t1);//from right
                    if (ans) return ans;
                    t1.clear();
                    t1.push_back(make_pair(i,j));
                    ans = callR(board,1,0,i,j+1,t1);//from left
                    if (ans) return ans;
                    t1.clear();
                    t1.push_back(make_pair(i,j));
                    ans = callR(board,1,2,i-1,j,t1);//f bottom
                    if (ans) return ans;
                    t1.clear();
                    t1.push_back(make_pair(i,j));
                    ans = callR(board,1,3,i+1,j,t1);//top
                    if (ans) return ans;
                }
            }
        }
        return ans;
    }
};

int main(){
	//vector<vector<char>> board = {{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};	
	vector<vector<char>> board = {{'a','a'}};	
	Solution inst;
	bool ans = inst.exist(board,"aa");
	cout << ans << '\n';
	return 0;
}

