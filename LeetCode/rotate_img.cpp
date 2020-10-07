
/*------------------------------------------------------------------------------------------
Author: JugheadJones13
Site: 	
Date: 2020 Oct 07 03:52:20 PM	

--------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& matrix){
	for (auto x:matrix){
		for (auto y:x){
			cout << y << " ";
		}
		cout << '\n';
	}
}

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int nrounds = n / 2;
				int shamt;
				int a = 0;
				print(matrix);
        for (int i = 0; i < nrounds; i++){
						shamt = n - a * 2 - 1;
						a++;
            int s_row = i;
            int s_col = i;
            for (int j = 0; j < shamt; j++){
                int save = matrix[s_row][s_col];
                //left col
                for (int k = 0; k < shamt; k++){
                    matrix[s_row+k][s_col] = matrix[s_row+k+1][s_col];
                }
                //bottom row
                for (int k = 0; k < shamt; k++){
                    matrix[s_row+shamt][s_col+k] = matrix[s_row+shamt][s_col+k+1];
                }
                //right col
                for (int k = 0; k < shamt; k++){
                    matrix[s_row+shamt-k][s_col+shamt] = matrix[s_row+shamt-k-1][s_col+shamt];
                }
                //top row
                for (int k = 0; k < shamt; k++){
                    matrix[s_row][s_col+shamt-k] = matrix[s_row][s_col+shamt-k-1];
                }
                matrix[s_row][s_col+1] = save;
            }
						print(matrix);
        }
        return;
    }

int main(){
	vector<vector<int>> matrix = {{2,29,20,26,16,28},{12,27,9,25,13,21},{32,33,32,2,28,14},{13,14,32,27,22,26},{33,1,20,7,21,7},{4,24,1,6,32,34}};	
	rotate(matrix);
	return 0;
}

