#include<bits/stdc++.h>
using namespace std;


class kStacks
{
public:
    int size, no_of_stacks, free;
    int *arr, *next, *top;

    kStacks(int s, int n){
        size = s;
        no_of_stacks = n;
        free = 0;
        arr = new int[s];
        next = new int[s];
        top = new int[n];

        for(int i=0;i<n-1;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        
        for(int i=0;i<n;i++){
            top[i] = -1;
        }
    }

    bool isFull(int stk_no){
        return free == -1;
    }

    bool isEmpty(int stk_no){
        return top[stk_no] == -1;
    }

    void push(int x, int stk_no){
        int i = free;
        arr[i] = x;
        free = next[i];
        next[i] = top[stk_no];
        top[stk_no] = i;
    }

    int pop(int stk_no){
        int ans = arr[top[stk_no]];
        int i = top[stk_no];
        top[stk_no] = next[i];
        next[i] = free;
        free = i;
        return ans;
    }
};

/* Driver program to test twoStacks class */
int main()
{
	// Let us create 3 stacks in an array of size 10
	int k = 3, n = 10;
	kStacks ks(k, n);

	// Let us put some items in stack number 2
	ks.push(15, 2);
	ks.push(45, 2);

	// Let us put some items in stack number 1
	ks.push(17, 1);
	ks.push(49, 1);
	ks.push(39, 1);

	// Let us put some items in stack number 0
	ks.push(11, 0);
	ks.push(9, 0);
	ks.push(7, 0);

	cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
	cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
	cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

	return 0;
}
