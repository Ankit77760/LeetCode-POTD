//1382. Balance a Binary Search Tree
/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105
*/

//Solutions
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedElements;
        inOrderTraversal(root, sortedElements);
        return buildBalancedBST(sortedElements, 0, sortedElements.size() - 1);
    }

private:
    void inOrderTraversal(TreeNode* node, vector<int>& sortedElements) {
        if (!node) {
            return;
        }
        inOrderTraversal(node->left, sortedElements);
        sortedElements.push_back(node->val);
        inOrderTraversal(node->right, sortedElements);
    }
    
    TreeNode* buildBalancedBST(const vector<int>& elements, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(elements[mid]);
        node->left = buildBalancedBST(elements, start, mid - 1);
        node->right = buildBalancedBST(elements, mid + 1, end);
        return node;
    }
};