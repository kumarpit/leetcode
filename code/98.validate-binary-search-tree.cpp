// Category: algorithms
// Level: Medium
// Percent: 34.116283%

// Given the root of a binary tree, determine if it is a valid binary search
// tree (BST).
//
// A valid BST is defined as follows:
//
//
// 	The left subtree of a node contains only nodes with keys less than the
// node's key. 	The right subtree of a node contains only nodes with keys
// greater than the node's key. 	Both the left and right subtrees must
// also be binary search trees.
//
//
//  
// Example 1:
//
// Input: root = [2,1,3]
// Output: true
//
//
// Example 2:
//
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the tree is in the range [1, 10⁴].
// 	-2³¹ <= Node.val <= 2³¹ - 1
//

#include <optional>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool isValidBST(TreeNode *root) { return isValidBST(root, nullopt, nullopt); }

private:
  bool isValidBST(TreeNode *root, optional<int> left, optional<int> right) {
    if (!root)
      return true;
    if ((left.has_value() && root->val <= left.value()) ||
        (right.has_value() && root->val >= right.value())) {
      return false;
    }
    return isValidBST(root->left, left, root->val) &&
           isValidBST(root->right, root->val, right);
  }
};
