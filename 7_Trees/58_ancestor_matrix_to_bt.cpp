#include <bits/stdc++.h>
using namespace std;
#define N 6

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node *ancestorTree(int mat[][N])
{
    multimap<int, int> mm;

    for (int i = 0; i < N; i++)
    {
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            count += mat[i][j];
        }
        mm.insert(pair<int, int>(count, i));
    }

    vector<Node *> nodes(N, NULL);
    vector<bool> parentSet(N, false);

    Node* root = NULL;

    for (auto x : mm)
    {

        int index = x.second;
        nodes[index] = newNode(index);
        root=nodes[index];

        if (x.first != 0)
        {
            for (int j = 0; j < N; j++)
            {
                if (!parentSet[j] && mat[index][j] == 1)
                {
                    if (nodes[index]->left == NULL)
                    {
                        nodes[index]->left = nodes[j];
                    }
                    else if (nodes[index]->right == NULL)
                    {
                        nodes[index]->right = nodes[j];
                    }
                    parentSet[j] = true;
                }
            }
        }
    }
    return root;
}

void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
    int mat[N][N] = {{0, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 1, 0},
                     {0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {1, 1, 1, 1, 1, 0}};

    Node *root = ancestorTree(mat);
    cout << "Inorder traversal of tree is \n";
    printInorder(root);
    return 0;
}
