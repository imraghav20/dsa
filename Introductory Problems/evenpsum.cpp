#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll a, b, ao=0, ae=0, bo=0, be=0;
        cin >> a >> b;
        if( a%2==0 ){
            ao = a/2;
            ae = a/2;

        }
        else{
            ao = a/2 + 1;
            ae = a/2;

        }

        if( b%2==0 ){
            bo = b/2;
            be = b/2;
        }

        else{
            bo = b/2 + 1;
            be = b/2;
        }

        ll pp = ao*bo + ae*be;
        cout << pp << "\n";
        

    }
    return 0;
}