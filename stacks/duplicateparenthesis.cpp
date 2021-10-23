#include<bits/stdc++.h>
using namespace std;

bool duplicateParentheses(string str){
    stack<int> s;
    int last_open = -1;
    int last_close = -1;
    int n = str.size();
    for(int i=0; i<n; i++){
        if(str[i]=='('){
            s.push(i);
        }
        else if (str[i]==')'){
            int open = s.top();
            s.pop();
            if(last_open-open==1 and i-last_close==1) return true;
            last_open = open;
            last_close = i;
        }
        
    }
    return false;
    
}


/*

//another Method
/Expected Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

bool duplicateParentheses(string str){
    
    stack<char> Stack;
  
    for (char ch : str)
    {   

        //if its a closing bracket eat up all the expression inside it
        // so if the next will also be a closing bracket then, it will again try to eat all the expressison before (
        // but if (( started togther the second ) will have nothing to eat

        if (ch == ')')
        {
            char top = Stack.top();
            Stack.pop();
  
            int elementsInside = 0;
            while (top != '(')
            {
                elementsInside++;
                top = Stack.top();
                Stack.pop();
            }
            if(elementsInside < 1) {
                return true;
            }
        }
  
        else
            Stack.push(ch);
    }
  
    return false;
    
}

*/