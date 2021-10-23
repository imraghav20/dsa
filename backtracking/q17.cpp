#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>




typedef long long ll;


#define big2(a, b) (a>b)?a:b
#define sml2(a, b) (a>b)?b:a
#define big3(a, b, c) (((a>b)?a:b)>c)?((a>b)?a:b):c
#define sml3(a, b, c) (((a>b)?b:a)>c)?c:((a>b)?b:a)

using namespace std;

int main()
{
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   vector<int> v;
   stack<int> s;
   int n, ctr=0, ctr2=0, m=0, m2=0, pos1, pos2;
   cin>>n;
   for(int i=0; i<n; i++){
       int a;
       cin>>a;
       v.push_back(a);
   }
   for(auto it=v.begin(); it!=v.end(); it++){
       if(*it==1){
           ctr++;
           s.push(*it);
       }
       else {
           int b = big2(m, ctr);
           if(m<b){
               pos1= (it-v.begin());
               m=big2(m, ctr);
           }
           s.pop();
           ctr=0;
       }
       if(!s.empty())
           ctr2++;
       else{
           int b = big2(m2, ctr2);
           if(m2<b){
               m2 = big2(m2, ctr2);
               pos2=std::distance(v.begin(), it)-m2+1;
               
           }
           ctr2=0;
       }  
   }
   cout<<m<<" "<<pos1<<" "<<m2+1<<" "<<pos2;
   return 0;
}
