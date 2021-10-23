#include <string>
#include<iostream>
#include<vector>
using namespace std;


void recur(int n, int i, string current){
    if(i==n){
        current= current+"()";
        cout<<current;
        return;
    }
    current+="(";
    recur(n,i+1, current);
    current[i] = ')';
}
vector<string> generateParenthesis(int n) {
    recur(n,0,"");
}
int main(){
    generateParenthesis(4);
}