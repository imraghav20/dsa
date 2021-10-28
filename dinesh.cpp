#include<iostream>
using namespace std;
#include<bits/stdc++.h>
vector<vector<int>>v;
vector<int> g(vector<int>a,vector<int>b)
{
    vector<int>q;
    q.assign(a.size()+b.size()-1,0);
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            q[i+j]+=a[i]*b[j];
        }
    }
    return q;
}
void f()
{
    vector<int>c(v[0]);
    for(int i=1;i<v.size();i++)
    {
        c=g(c,v[1]);
    }
    reverse(c.begin(),c.end());
    for(int i=0;i<c.size();i++)
    {
            cout<<c[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int k;
    int h;
    int e;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>h;
        vector<int>v1;
        while(h--)
        {
            cin>>e;
            v1.push_back(e);
        }
        reverse(v1.begin(),v1.end());
        v.push_back(v1);
    }
    f();
    return 0;
}
