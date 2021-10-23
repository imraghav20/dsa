#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

typedef long long ll;


class non_repeat{
    public :
    int digit_uniq = 0;

    bool check1(int bits, int i){
        return ( !bits && !i);
    }

    bool check2(int bits, int i){
        return ((bits & ( 1<<i)) > 0);
    }

    void recurr(ll now, int bits, int& n){
        if( now > n )return;
        else{
            ++digit_uniq;
        }

        for( int i = 0; i < 10; i++){
            if( check1(bits, i) )continue;
            if( check2(bits, i) )continue;
            recurr( now*10+i, bits | ( 1<<i),n );
        }
    }

    int repeated_digits(int n){
        recurr( 0, 0, n);
        return digit_uniq - 1;
    }

};




    


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

    non_repeat nr;

    int ans = nr.repeated_digits(n);


    

    cout << n - ans;

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
