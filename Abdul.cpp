#include <bits/stdc++.h>
using namespace std;

int one_to_n(int n)
{
    string s = to_string(n);
    int l = s.size();
    int norepeated = 9;
    int repeated = 0;
    int ans = 0;
    for (int i = 2; i < l; i++)
    {
        int a = norepeated * (i - 1);
        int b = repeated * 10;
        repeated = a + b;
        ans += repeated;
        norepeated = pow(10, i) - pow(10, i - 1) - repeated;
        // cout<<repeated<<" "<<norepeated<<" "<<ans+1<<endl;
    }
    return ans + 1;
}

int findval(int a,vector<int>&vis){
    int ans=0;
   for (int j = a + 1; j < 10; j++){
ans += (vis[j] == 0);
    }
    return ans;
}

void helper(vector<int> &dp, vector<int> &vis, int &sameval, string s, int i)
{
    
    int a = s[i] - '0';
    int diffrent=findval(a,vis);
 
        
    dp[i] -= diffrent;
    vis[a]++;
    if (vis[a] > 1){
sameval = 1;
    }
        
}

int solve(int n, int x)
{
    vector<int> vis(10, 0);
    string s = to_string(n);
    int len = s.size();
    vector<int> dp(len, 0);

    

    int sameval = 0;
    for (int i = 0; i < len; i++)
    {
        
        if(i==0){
            dp[i]=9;
        }
        else{
            dp[i]=dp[i - 1] * (10 - i);
        }
       
        if (!sameval)
        {
            helper(dp, vis, sameval, s, i);
        }
    }
    return x - dp[len - 1];
}

int main()
{
    int n;
    cin >> n;
    int a = one_to_n(n);
    string s = to_string(n);
    int x = n - pow(10, s.size() - 1);
    int b = solve(n, x);
    // int b=
    cout << a + b << endl;

    return 0;
}
