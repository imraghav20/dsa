#include<bits/stdc++.h>
using namespace std;



int solve(string s,int i,int j){
    if(i>j){
        return 0;
    }
    if(s[i]==s[j]){
        return solve(s,i+1,j-1);
    }
    int a=1+solve(s,i+1,j);
    int b=1+solve(s,i,j-1);
    return min(a,b);
}

int main(){
   int n;
string s;
cin>>n;
    cin>>s;


 
   int ans=solve(s,0,n-1);
   cout<<ans;
   return 0;


}
