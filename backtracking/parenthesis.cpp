#include <string>
#include<iostream>
#include<vector>

#define max 10000

typedef long long ll;

using namespace std;



void recur(int n, int i, string current){
    if(n==i){
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
