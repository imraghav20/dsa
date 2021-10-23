#include<bits/stdc++.h>
using namespace std;

void copyMat(vector<vector<int>> mat,vector<vector<int>> &copy, int n, int m){
    for(int i=0; i<n;i++ ){
        for(int j=0; j<m; j++){
            copy[i][j] = mat[i][j];
        }
    }
}


void helper(vector<vector<int>>& mat, vector<string> arr,int n,int m, int i, int j, vector<vector<int>>& copy){

    //base case
    if(i==n-1 and j ==m-1){
        copyMat(mat,copy,n,m);
        return;
    }

    //recursive case
    if(j<m-1 and arr[i][j+1]=='O' and mat[i][j+1]!=1){ // checking the third condition to ensure we dont return to coming path
        mat[i][j+1]=1;
        helper(mat,arr,n,m,i, j+1, copy);
        mat[i][j+1]=0;

    }
    if(i<n-1 and arr[i+1][j]=='O' and mat[i+1][j]!=1){
        mat[i+1][j]=1;
        helper(mat,arr,n,m,i+1, j, copy);
        mat[i+1][j]=0;

    }
    if(j>0 and arr[i][j-1]=='O' and mat[i][j-1]!=1){
        mat[i][j-1]=1;
        helper(mat,arr,n,m,i, j-1, copy);
        mat[i][j-1]=0;

    }
    if(i>0 and arr[i-1][j]=='O' and mat[i-1][j]!=1){
        mat[i-1][j]=1;
        helper(mat,arr,n,m,i-1, j, copy);
        mat[i-1][j]=0;
    }
}
vector<vector<int>> ratAndMice(vector<string> arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> mat(n, vector<int> (m, 0));
    vector<vector<int>> copy(n, vector<int> (m, 0));
    mat[0][0]=1;
    helper(mat, arr, n,m,0,0,copy);
    return copy;
}
int main(){
    vector<string> arr = {"OOOO", "XXOX", "XXOX", "XXOO"};
    vector<vector<int>> copy = ratAndMice(arr);
    for(auto x: copy){
        for(auto y: x){
            cout<<y;
        }
        cout<<endl;
    }
    return 0;
}