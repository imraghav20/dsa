#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;


int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        int t[m+1][n+1];
        for( int i = 0; i < m+1; i++){
            for( int j =0; j < n+1; j++){
                if( i == 0 || j == 0 ){
                    t[i][j] = 0;
                }
            }
        }
        for( int i = 1; i < m+1; i++){
            for( int j = 1; j < n+1; j++){
                if( text1[i-1] == text2[j-1] ){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                    
                }
            }
        }
        
        
        
        return t[m][n];
        
    }
    int longestPalindromeSubseq(string s) {
        string str(s);
        reverse(str.begin(), str.end());
        
        return longestCommonSubsequence(s,str);
    }


bool comp(pair < int , pair < int , int > >&,pair < int , pair < int , int > >&);
void swap(int&, int&);
void rotate_sub(vector < int >&, int, int);
int find_min_vertex(vector < int >&, vector < bool > &, int);
void add_edge(vector < vector <int> >&, int, int);
void union_find(int, int);
vector <int > root(10001);
int find_root(int);



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int lps = longestPalindromeSubseq(s);

    cout << n-lps ;

    return 0;
}


bool comp( pair < int , pair < int , int > >&a,  pair < int , pair < int , int > >&b){
    return a.first < b.first ;
}

void swap( int& a, int& b){
        int temp = b;
        b = a;
        a = temp;
    }
    void rotate_sub( vector < int > & nums, int start, int end){
        for ( int i = start; i<=(start+end)/2; i++){
            swap(nums[i], nums[end]);
            end--;
            
        }
    }

int find_min_vertex( vector < int > &  dist, vector < bool > & vis, int n){
    int min_val = INT_MAX;
    int min_vertex;
    for( int i = 0; i < n; i++){
        if( !vis[i] && (dist[i] < min_vertex) ){
            min_vertex = i;
            min_val = dist[i];
        }
    }
    
    return min_vertex;
}

void add_edge( vector < vector <int> >& adj, int a, int b){
  adj[a].push_back(b);
  adj[b].push_back(a);
}
int find_root(int a){
    while( a != root[a] ){
        a = root[a];
    }
    return a;
}



void union_find(int a, int b){
    int x = find_root(a);
    int y = find_root(b);
    if( x != y )root[b] = root[y];
}
