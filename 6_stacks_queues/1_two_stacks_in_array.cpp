#include<bits/stdc++.h>
using namespace std;

struct twoStacks{
    int size;
    int *arr;
    int top1, top2;

    twoStacks(int n){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x){
        if(top1<top2-1){
            top1++;
            arr[top1] = x;
        }
        else{
            cout<<"Stack Overflow!";
        }
    }

    void push2(int x){
        if(top1<top2-1){
            top2--;
            arr[top2] = x;
        }
        else{
            cout<<"Stack Underflow!";
        }
    }

    int pop1(){
        if(top1>=0){
            int top = arr[top1];
            top1--;
            return top;
        }else{
            cout<<"Cannot Pop";
            return -1;
        }
    }

    int pop2(){
        if(top2>=0){
            int top = arr[top2];
            top2++;
            return top;
        }else{
            cout<<"Cannot Pop";
            return -1;
        }       
    }
};

int main(){
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "<< ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is "<< ts.pop2();
    return 0;   
}