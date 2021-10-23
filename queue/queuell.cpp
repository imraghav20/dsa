#include<iostream>
#include "queue_ll.h"
using namespace std;

int main(){
    queue<int> okay;
    okay.push(4);
    okay.push(2);
    okay.push(1);
    okay.push(5);
    cout<<okay.front()<<endl;
    okay.pop();
    cout<<okay.front()<<endl;

}