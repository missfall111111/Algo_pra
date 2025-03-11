#include <vector>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


const int MAXN = 2000;
TreeNode* arr[MAXN];
int l = 0;
int r = 0;
class Solution {
	public:
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			vector<vector<int>>ans;
			bool reverse = false;
			if (root == nullptr) {
				return ans;
			}
			arr[r++] = root;
			while (l != r) {
				int t = r - l;
				vector<int>a;
				for (int i = 0, pos = reverse ? r - 1 : l; i < t; i++, pos += reverse ? -1 : 1) {
					a.push_back(arr[pos]->val);
				}
				ans.push_back(a);
				for (int i = 0; i < t; i++) {
					if (arr[l]->left != nullptr) {
						arr[r++] = arr[l]->left;
					}
					if (arr[l]->right != nullptr) {
						arr[r++] = arr[l]->right;
					}
					l++;
				}
				reverse=!reverse;
			}
			return ans;
		}
};
