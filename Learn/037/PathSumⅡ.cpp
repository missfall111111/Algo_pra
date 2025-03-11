#include <vector>
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

class Solution {
	public:
		void cpPath(vector<int>&curPath, vector<vector<int>> &paths) {
			vector<int>a;
			for (auto i : curPath) {
				a.push_back(i);
			}
			paths.push_back(a);
		}
		void f(TreeNode* node, int sum, int tar, vector<int> &curPath, vector<vector<int>>&paths) {
			sum += node->val;
			curPath.push_back(node->val);
			if (node->left == nullptr && node->right == nullptr) {
				if (sum == tar) {
					cpPath(curPath, paths);
				}
				return;
			} else {
				if (node->left != nullptr) {
					f(node->left, sum, tar, curPath, paths);
					curPath.pop_back();
				}
				if (node->right != nullptr) {
					f(node->right, sum, tar, curPath, paths);
					curPath.pop_back();
				}
				return;
			}
		}
		vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
			vector<vector<int>>paths;
			if (root != nullptr) {
				vector<int> path;
				f(root, 0, targetSum, path, paths);
			}

			return paths;
		}
};
