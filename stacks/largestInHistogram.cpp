#include<bits/stdc++.h>
using namespace std;
 
int getMaxArea(vector<int> hist){
    stack<int> indices;
    int n = hist.size();
    int maxArea=-1;
    int i =0;
    while(i<n){
        if(indices.empty() or hist[i]>=hist[indices.top()]){ //if stack is empty of current element is greater
            indices.push(i); //push i
            i++;
        }
        else{
            int area=0;
            int top = indices.top();
            indices.pop();
            if(indices.empty()){ //Top has no left boundary i.e. all bars untill i have atleast hist[top] height
                area = hist[top]*i;
            }
            else{
                int prev_to_top = indices.top();
                area = hist[top]*(i-prev_to_top-1);   //area of top = height of top * (right smaller boundary-left smaller boundary -1)
            }
            maxArea = max(area, maxArea);
            //NOTE THAT WE ARE NOT UPDATING i BECAUSE WE WANT To REPEAT FOR ALL ELEMENT IN STACK UNTILL WE FIND SMALLER FOR hist[i].(THEN ONLY PREVIOUS TO TOP WILL BE LEFT BOUNDARY in next iterations)
        }
    }
    while(indices.empty() == false){
        int area;
        int top = indices.top();
        indices.pop();
        if(indices.empty()){ //Top has no left boundary i.e. all bars untill i have atleast hist[top] height
            area = hist[top]*i;
        }
        else{
            int prev_to_top = indices.top();
            area = hist[top]*(i-prev_to_top-1);   //area of top = height of top * (right smaller boundary-left smaller boundary -1)
        }
        maxArea = max(area, maxArea);
        //NOTE THAT WE ARE NOT UPDATING i BECAUSE WE WANT To REPEAT FOR ALL ELEMENT IN STACK UNTILL WE FIND SMALLER FOR hist[i].(THEN ONLY PREVIOUS TO TOP WILL BE LEFT BOUNDARY in next iterations)
    }
    return maxArea;
}



int main(){
    vector<int> in ={6,2,5,4,5,1,6};
    cout<<getMaxArea(in);
}