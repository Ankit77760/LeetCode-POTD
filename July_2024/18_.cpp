//1530. Number of Good Leaf Nodes Pairs
/*
You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

 

Example 1:


Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
Example 2:


Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
Example 3:

Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].
 

Constraints:

The number of nodes in the tree is in the range [1, 210].
1 <= Node.val <= 100
1 <= distance <= 10
Accepted
101,132
Submissions
146,188/*

*/
//Solutions
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& ans) {
        if (!node) return {};
        if (!node->left && !node->right) return {0};

        auto leftDistances = dfs(node->left, distance, ans);
        auto rightDistances = dfs(node->right, distance, ans);

        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r + 2 <= distance) ans++;
            }
        }

        vector<int> distances;
        for (int l : leftDistances) distances.push_back(l + 1);
        for (int r : rightDistances) distances.push_back(r + 1);
        return distances;
    }
};