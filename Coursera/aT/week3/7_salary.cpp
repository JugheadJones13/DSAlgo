#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool IsGreaterOrEqual(int a,int b){
    string a_s = to_string(a);
    string b_s = to_string(b);
    string c = a_s + b_s;
    string d = b_s + a_s;
    int c_i = stoi(c);
    int d_i = stoi(d);
    if (c_i > d_i){
        return true;
    }
    else return false;
}

void findSol(vector<int>* digits,vector<int>* ans){
    int maxdigit;
    while (!digits->empty()){
        maxdigit = -1000000;
        for (int i = 0; i < digits->size(); i++){
            if (IsGreaterOrEqual(digits->at(i),maxdigit)){
                maxdigit = digits->at(i);
            }
        }
        auto it = find(digits->begin(),digits->end(),maxdigit);
        ans->push_back(maxdigit);
        digits->erase(it);
    }
    return;
}

int main(){
    int n,x;
    cin >> n;
    vector<int> digits;
    for (int i = 0; i < n; i++){
        cin >> x;
        digits.push_back(x);
    }
    vector<int> answer;
    findSol(&digits,&answer);
    string ans = "";
    for (auto x: answer){
        ans += to_string(x);
    }
    cout << ans << endl;
}