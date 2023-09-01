#include <bits/stdc++.h>

using namespace std;

struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;
};

void MorrisTraversalInorder(struct tNode *root) 
{
    while (root != NULL)
    {
        if (root->left == NULL)
        {
            cout << root->data << " ";
            root = root->right; // go to the connection
        }
        else
        {
            tNode *prev = root->left;

            while (prev->right && prev->right != root)
            {
                prev = prev->right; // go on to the right most node
            }

            if (prev->right == NULL)
            {
                prev->right = root;
                root = root->left; // make connection
            }
            else
            {
                cout << root->data << " ";
                prev->right = NULL;
                root = root->right; 
            }
        }
    }
}

void MorrisTraversalPreorder(struct tNode *root) 
{
    while (root != NULL)
    {
        if (root->left == NULL)
        {
            cout << root->data << " ";
            root = root->right;
        }
        else
        {
            tNode *prev = root->left;

            while (prev->right && prev->right != root)
            {
                prev = prev->right; // go on to the right most node
            }

            if (prev->right == NULL)
            {
                prev->right = root;
                cout << root->data << " "; // print when making connection
                root = root->left; // make connection
            }
            else
            {
                //cout << root->data << " ";
                prev->right = NULL;
                root = root->right; // go to the connection
            }
        }
    }
}

struct tNode *newtNode(int data)
{
    struct tNode *node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
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
    struct tNode *root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);

    MorrisTraversal(root);

    return 0;
}
