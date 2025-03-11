#include <algorithm>
#include<iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//意不在高度
class Solution {
	public:
		bool balance;
		bool isBalanced(TreeNode* root) {
			balance = true;
			if (root != nullptr) {
				height(root);
			}
			return balance;
		}

		int height(TreeNode* root) {
			if (root->right == nullptr && root->right == nullptr) {
				return 1;
			}
			int lh = 0, rh = 0;
			if (root->left != nullptr) {
				lh = height(root->left);
			}
			if (root->right != nullptr) {
				rh = height(root->right);
			}
			
			cout<<"I'm"<<root->val<<"my l is"<<lh<<" my r is"<<rh<<"\n";
			if (abs(lh - rh) > 1) {
				balance = false;
			}
			return max(lh, rh) + 1;
		}
};
