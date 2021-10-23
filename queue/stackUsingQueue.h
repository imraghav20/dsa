#include<queue>
using namespace std;
template<typename T>
class stack{
    queue<T> q1;
    queue<T> q2;
    int flag = 0;
    public:
        stack(){
            flag = 0;
        }

        void push(T d){
            if(q2.empty()){
                q1.push(d);
            }
            else{
                q2.push(d);
            }   
        }
        void pop(){
            if(q2.empty() and q1.empty()){
                return;
            }
            else if(q2.empty()){
                T temp;
                while(!q1.empty()){
                    temp=q1.front();
                    q1.pop();
                    if(!q1.empty()) q2.push(temp);
                }
            }
            else if(q1.empty()){
                T temp;
                while(!q2.empty()){
                    temp=q2.front();
                    q2.pop();
                    if(!q2.empty()) q1.push(temp);
                }
            }
        }

        T top(){
            T temp;
            if(!q1.empty()){
                while(!q1.empty()){
                    temp = q1.front();
                    q1.pop();
                    q2.push(temp);
                }
            }
            else if(!q2.empty()){
                while(!q2.empty()){
                    temp = q2.front();
                    q2.pop();
                    q1.push(temp);
                }
            }
            return temp;
        }

        bool empty(){
            return q1.empty() and q2.empty();
        }
        
};