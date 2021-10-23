#include <bits/stdc++.h>
using namespace std;

bool lookup(string word, vector<string> &dictionary){
    for(auto x: dictionary){
        if (x==word){
            return true;
        }
    }
    return false;
}

void helper(string str, vector<string> &dictionary, int i, string current, int& count){
    int n = str.size();
    for (int i = 1; i<=n; i++){ //from 1 to n because to create substring we take size as second parameter
        string sub = str.substr(0, i);
        if(lookup(sub, dictionary)){
            if(i==n){
                current= current+ sub;
                count++;
                return;
            }
            helper(str.substr(i,n-i), dictionary, i, current+sub+" ", count);
        }
    }
}

int wordBreak(string str, vector<string> &dictionary){
	int count=0;
    helper(str, dictionary, 0, "", count);
    return count;
}

int main(){
    vector<string> dict = {"i", "like", "yo","u", "you"};
    string s = "ilikeyou";
    cout<<wordBreak(s,dict);
}