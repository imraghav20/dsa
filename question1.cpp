#include<bits/stdc++.h>
using namespace std;

vector<int> input( ){

    string s;
  
    getline(cin,s);
    vector<int>arr;
    string ss=" ";
    for(int i=0;i<s.size();i++){

        if(s[i]==' '){
            int a;
            stringstream val;
            val<<ss;
            val>>a;
            arr.push_back(a);
            ss=" ";
        }
        if(i==s.size()-1){
            ss+=s[i];
            int a;
            stringstream val;
            val<<ss;
            val>>a;
            arr.push_back(a);

        }
        else{
            ss+=s[i];
        }
    }
    return arr;

}

int multiply(vector<int>e1,vector<int>e2,int i,int j){
    return e1[i]*e2[j];
}

void printans(vector<int>ans){
    int n=ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}

vector<int> solve(vector<int>e1,vector<int>e2){
    int n=e1.size();
    int m=e2.size();
    int k=n+m-2;
    vector<int>ans(k+1,0);
    for(int i=0;i<n;i++){
        int j=0;
        while(j<m){
            ans[i+j]+=multiply(e1,e2,i,j);
            
            j++;
        }
    }
    
    // printans(ans);
    return ans;

}

int main(){


    int n=0;
    cin>>n;
      cin.ignore();
    vector<int>equa1=input();
     
    vector<int>equa2=input();
    
    vector<int>ans=solve(equa1,equa2);
    if(n>2){
        int k=n-2;
        while(k--){
            vector<int>equ3=input();
            ans=solve(ans,equ3);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    // printans(equa1);
    // cout<<endl;
    // printans(equa2);

    return 0;


}
