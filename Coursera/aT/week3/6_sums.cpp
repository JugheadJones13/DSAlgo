#include <iostream>
#include <vector>
using namespace std;

void findSol(vector<int>* ans,int ip){
    ans->push_back(1);
    int curr_sum = 1;
    bool stop = false;
    int last;
    while (1){
        if (curr_sum == ip) return;
        if (curr_sum < ip){
            ans->push_back(ans->back()+1);
            curr_sum += ans->back();
        }
        else{
            last = ans->back();
            ans->erase(ans->end()-1);
            curr_sum -= ans->back();
            ans->erase(ans->end()-1);
            ans->push_back(last);
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> ans;
    findSol(&ans,n);
    cout << ans.size() << endl;
    for (auto x: ans)
        cout << x << " ";
    cout << endl;
}