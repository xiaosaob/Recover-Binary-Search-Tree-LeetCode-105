// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        helper(root, prev, first, second);
        swap(first->val, second->val);
    }
    
    void helper(TreeNode *root, TreeNode* &prev, TreeNode* &first, TreeNode* &second) {
        if(!root) return;
        helper(root->left, prev, first, second);
        if(prev && prev->val > root->val) {
            if(!first) {
                first = prev;
                second = root;
            } else {
                second = root;
            }
        }
        prev = root;
        helper(root->right, prev, first, second);
    }
};
