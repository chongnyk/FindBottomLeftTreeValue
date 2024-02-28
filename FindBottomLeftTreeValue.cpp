/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> findValDepth(TreeNode* node) //find bottom left most value in any tree rooted at node along w depth of node measured in edges from node
    {
        pair<int, int> lVal, rVal;
        if(node->left != nullptr){
            lVal = findValDepth(node->left);
        }
        else {
            lVal = make_pair(node->val, 0);
        }

        if(node->right != nullptr){
            rVal = findValDepth(node->right);
        }
        else {
            rVal = make_pair(node->val, 0);
        }

        if(lVal.second >= rVal.second){
            lVal.second += 1;
            return lVal;
        }
        else{
            rVal.second++;
            return rVal;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> result = findValDepth(root);
        return result.first;
    }
};
