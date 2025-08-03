#include<bits/stdc++.h>
using namespace std;

// left idx = parent * 2 + 1
// right idx = parent * 2 + 2

// heap er formula

//  parent = ( left - 1 ) / 2
int main(){
    int n; cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int val; cin >> val;
    v.push_back(val);

    int cur_idx = (int)v.size() - 1;
    int par_idx = (cur_idx - 1) / 2;
    while(v[par_idx] < v[cur_idx]){
        swap(v[par_idx],v[cur_idx]);
        cur_idx = par_idx;
        par_idx = (cur_idx - 1) / 2;
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}