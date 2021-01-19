// Copyright DB 2021

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <iostream>

template <class T>
class MyStack {
 private:
     T* stack;
     int size = 0;
     int position = 0;

 public:
     explicit MyStack(int s_) {
         size = s_;
         stack = new T[size];
     }
     ~MyStack() {
         delete[] stack;
     }
     MyStack(const MyStack& st) {
         size = st.size;
         stack = new T[size];
         for (int i = 0; i < size; ++i) {
             stack[i] = st.stack[i];
         }
         position = st.position;
     }
     int getSize() {
         return size;
     }
     bool isFull() {
         if (position == size) {
             return true;
         } else {
             return false;
         }
     }
     bool isEmpty() {
         if (position == 0) {
             return true;
         } else {
             return false;
         }
     }
     T& get() {
         if (size != 0) {
             int position_ = position - 1;
             return stack[position_];
         } else {
             std::cout << "stack is empty";
         }
     }
     T& pop() {
         if (size != 0) {
             position--;
             return stack[position];
         } else{
             std::cout << "stack is empty";
         }       
     }
     void push(double x) {
         if (position < size) {
             stack[position] = x;
             position++;
         } else if (position == size){
             std::cout << "stack is full";
         }
     }
};
#endif  //  INCLUDE_MYSTACK_H_
