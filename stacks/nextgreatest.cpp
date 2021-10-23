#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> v){
    int n = v.size();
    stack<int> s;
    vector<int> res(n,-1);
    //store in reverse manner
    for(int i=n-1; i>=0; i--){
        int current = v[i];
        while(!s.empty() and current>=s.top()){
            s.pop();
        }
        if(s.empty()){
            res[i] = -1;
        }
        else{
            int prev_high = s.top();
            res[i] = prev_high;
        }
        s.push(current);
    }
    return res;
}

int main(){
    vector<int> in = {1,4,2,6,8,1,2};
    for(auto i: nextGreaterElement(in)){
        cout<<i<<" ";
    }
}