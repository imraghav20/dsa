/*

Given a string A, partition A such that every substring of the partition is a palindrome. 
Return the minimum cuts needed for a palindrome partitioning of A.

*/


bool ispalindrome(int i, int j,string A){
    while(i<j){
        if(A[i]!=A[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int solve(string x,int i,int j,vector<vector<int>> &dp){
    //if(i>j) return 0;
    //if(i==j) return dp[i][j] = 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(ispalindrome(i,j,x)==true) return dp[i][j] =  0;
    //if(j-i<=2) return dp[i][j] = 1;
    int ans = INT_MAX;
    //int temp;
    int l;
    int h ;
    for(int  k = i;k<j;k++){
        if(dp[i][k]!=-1) l = dp[i][k] ;
        else l = solve(x,i,k,dp);
        if(dp[k+1][j]!=-1) h = dp[k+1][j] ;
        else h = solve(x,k+1,j,dp);
        
        int temp =temp = l + h ;
        ans = min(temp,ans);
    }
    
    return dp[i][j] = ans + 1;
}



int Solution::minCut(string A) {
    int i =0;
    int j = A.size()-1;
    int n = A.size();
    vector<vector<int> >dp(n+1,vector<int> (n+1,-1));
    return solve(A,i,j,dp);
    
}
