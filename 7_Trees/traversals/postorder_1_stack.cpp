#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node (int data)
	{
		this->data = data;
		left = right = NULL;
	}
};


// similiar to preorder
void postorderTraversal(Node* root) {
        vector<int> postorder;
        if(root==NULL)
            return;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            root=st.top();
            st.pop();
            postorder.push_back(root->data);
            if(root->left!=NULL)
                st.push(root->left);
            if(root->right!=NULL)
                st.push(root->right);      
        }
        reverse(postorder.begin(), postorder.end());
        
        for(auto x : postorder)
            cout<<x<<" ";
}




int main()
{
	/* Constructed binary tree is
			1
			/ \
		2	 3
		/ \
	4	 5
	*/

	struct Node *root = new Node(1);
	root->left	 = new Node(2);
	root->right	 = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

    postorderTraversal(root);

	return 0;
}
