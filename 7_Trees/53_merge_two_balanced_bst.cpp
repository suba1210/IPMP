1. Insert one bst to another bst => Time Complexity O(Mlogn)
2. Create inorder array of two bsts, both of them are sorted. Merge two sorted arrays
O(M+N) time. And form a bst from merged sorted arrays in O(M+N) time and O(M+N) space
3. Do the above with DLL which does it in-place, so time = O(M+N), space = O(M+N)
