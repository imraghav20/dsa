/*

Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?
Operands are only true and false.
Return the number of ways to evaluate the expression modulo 103 + 3.

*/



#define mod 1003
vector<vector<vector<int>>> dp;

int solve(string &A, int i, int j, int isTrue){
    if(i>j) return dp[i][j][isTrue]=0;
    if(i==j){
        if(isTrue){
            if(A[i]=='T') return dp[i][j][isTrue]=1;
            else return dp[i][j][isTrue]=0;
        }
        else{
            if(A[i]=='F') return dp[i][j][isTrue]=1;
            else return dp[i][j][isTrue]=0;
        }
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    int res=0;
    for(int k=i+1; k<j; k+=2){
        int lt= solve(A, i, k-1, 1);
        int lf= solve(A, i, k-1, 0);
        int rt= solve(A, k+1, j, 1);
        int rf= solve(A, k+1, j, 0);
        if(A[k]=='&'){
            if(isTrue){
                res=(res+lt*rt)%mod;
            }
            else{
                res=(res+lf*rt+lt*rf+rf*lf)%mod;
            }
        }
        else if(A[k]=='|'){
            if(isTrue){
                res=(res+lt*rt+lt*rf+lf*rt)%mod;
            }
            else res=(res+lf*rf)%mod;
        }
        else if(A[k]=='^'){
            if(isTrue){
                res=(res+lt*rf+rt*lf)%mod;
            }
            else{
                res=(res+lt*rt+lf*rf)%mod;
            }
        }
    }
    return dp[i][j][isTrue]=res%mod;
}

int Solution::cnttrue(string A){
    dp=vector<vector<vector<int>>>(A.size()+1, vector<vector<int>>(A.size()+1, vector<int>(2, -1)));
    return solve(A, 0, A.size()-1, 1);
}
