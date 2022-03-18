Approach:

1. We are given three linked list A, B, C, and expected sum
2. Sort B in ascending order and C in descending order using merge sort for linked list
3. Traverse the nodes of A one by one : 
    i) add a + b + c
    ii) if a+b+c > expected sum => decrement iterator of C
    iii) if a+b+c < expected sum => increment iterator of B