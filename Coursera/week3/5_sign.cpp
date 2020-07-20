#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct segment{
    int a;
    int b;
    segment(int x,int y):a(x),b(y){}
};

void findSol(vector<int>* ans,vector<segment>& ip){
    while (!ip.empty()){
        int curr_b = ip.front().b;
        ans->push_back(curr_b);
        for (auto it = ip.begin(); it != ip.end();){
            if (curr_b >= it->a && curr_b <= it->b){
                ip.erase(it);
            }
            else{
                it++;
            }
        }
    }
    return;
}

bool sortFunc(segment l,segment r){
    return (l.b < r.b);
}

int main(){
    int n,a,b;
    cin >> n;
    vector<segment> segments;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        segments.push_back(segment(a,b));
    }
    sort(segments.begin(),segments.end(),sortFunc);
    vector<int> ans;
    findSol(&ans,segments);
    cout << ans.size() << endl;
    for (auto x : ans) 
        cout << x << " ";
    cout << endl;

    return 0;

}