//Date: 06/27/2020
//URL: 	https://www.hackerrank.com/challenges/variable-sized-arrays/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,q;
    cin >> n >> q;
    vector <int> ** VecArray = new vector<int>* [n];
    int size,currNum;
    //create vector portion
    for (int i = 0; i < n; i++){    //this is for every vector
        cin >> size;
        VecArray[i] = new vector<int> [size];
        for (int j = 0; j < size; j++){
            cin >> currNum;
            VecArray[i]->push_back(currNum);
        }
    }
    //query portion
    int a,b;
    for (int k = 0; k < q; k++){
        cin >> a >> b;
        cout << (*VecArray[a])[b] << endl;
    }
    return 0;
}
