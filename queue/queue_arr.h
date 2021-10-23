#include<iostream>
using namespace std;


template<typename T>
class Queue{
    T* arr;
    int max_size;
    int current_size;
    int frontp;
    int rearp;
    public:
        Queue(int size){
            arr = new T[size];
            max_size=size;
            current_size=0;
            frontp = 0;
            rearp = max_size-1;
        }
        bool isFull(){
            return current_size==max_size;
        }
        bool empty(){
            return current_size==0;
        }
        void push(T d){
            if(!isFull()){
                rearp = (rearp+1)%max_size;
                arr[rearp] = d;
                current_size++;
            }
        }

        void pop(){
            if(!empty()){
                frontp=(frontp+1)%max_size;
                current_size--;
            }
        }
        T front(){
            return arr[frontp];
        }

};