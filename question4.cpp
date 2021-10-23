#include<bits/stdc++.h>
using namespace std;





int solve(vector<int>adj[],int n,int k,int m){
    if(m==0){
        if(n%k==0){
            return n/k;
        }
        return n/k+1;
    }
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto x:adj[i]){
            indegree[x]++;
        }
    }

    set<pair<int,int>>s;
    for(int i=0;i<n;i++){
        s.insert({indegree[i],i});
    }
    int ans=0;
    while(!s.empty()){
        int a=k;
        vector<int>record;
        while(a-- && !s.empty()){
            auto b=*(s.begin());
            if(b.first==0){
                s.erase(b);
                record.push_back(b.second);
                // cout<<b.second<<" ";
              
            }
        }
        for(int i=0;i<record.size();i++){
              for(auto x:adj[record[i]]){
                    s.erase({indegree[x],x});
                    indegree[x]--;
                    s.insert({indegree[x],x});
                }
        }
        // cout<<endl;
        ans++;
    }
    return ans;

}


void input(vector<int>&arr,int m){
    string s;
    cin.ignore();
    getline(cin,s);
    if(m==0){
        return ;
    }
      s.erase(remove(s.begin(), s.end(), ']'), s.end());
    s.erase(remove(s.begin(), s.end(), '['), s.end());
      
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
  ;
        string a="";
        ;
    for(int i=0;i<s.size();i++){
        if(s[i]==','){
            int b;
            stringstream ss;
            ss<<a;
            ss>>b;
            arr.push_back(b);
            a="";
            
            

        }
        else{
            a+=s[i];
        }

    }
     int b;
            stringstream ss;
            ss<<a;
            ss>>b;
            arr.push_back(b);
            a="";
    


}

int main(){

    int n,m;
    cin>>n>>m;
    vector<int>arr;
    input(arr,m);
    int k;
    cin>>k;
    
    vector<int>adj[n];
    for(int i=0;i<arr.size();i=i+2){
        adj[arr[i]-1].push_back(arr[i+1]-1); 
    }
    int ans=solve(adj,n,k,m);
    cout<<ans;
    return 0;
}
