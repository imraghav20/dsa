#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<int>v;
void f(string s,int l,int r,int c)
{
    if(s[l] == s[r] && l+1<r)
    {
        f(s,l+1,r-1,c);
    }
    else if(l==r-1 && s[l]!=s[r])
    {
        c++;
        v.push_back(c);
    }
    else if((l==r-1 && s[l]==s[r])|| (l==r))
    {
        v.push_back(c);
    }
    else
    {
        c++;
        f(s,l,r-1,c);
        f(s,l+1,r,c);
    }
}
int main()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    f(s,0,s.length()-1,0);
    cout<<*min_element(v.begin(),v.end())<<endl;
    return 0;
}