class Solution {
public:
    struct Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x){
            this->data = x;
            this->left = NULL;
            this->right = NULL;
        }
    };
    void preorder(vector<int>& ans, Node* root){
        if(root==NULL)
            return;
        ans.push_back(root->data);
        preorder(ans,root->left);
        preorder(ans,root->right);
    }
    Node* func(vector<int> nums, int start, int end){
        if(start>end)
            return NULL;
        int mid = (start+end)/2;
        Node* root = new Node(nums[mid]);
        root->left = func(nums, start, mid-1);
        root->right = func(nums, mid+1, end);
        return root;
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        Node* root = func(nums, 0, nums.size()-1);
        vector<int> ans;
        preorder(ans, root);
        return ans;
    }
};