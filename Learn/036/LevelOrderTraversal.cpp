#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


////普通bfs
//class Solution {
//	public:
//		vector<vector<int>> levelOrder(TreeNode* root) {
//			vector<vector<int>>ans;
//			if (root == nullptr) {
//				return ans;
//			}
//			unordered_map<TreeNode*, int>map;
//			queue<TreeNode*> q;
//			q.push(root);
//			map[root] = 0;
//			while (!q.empty()) {
//				TreeNode* tar = q.front();
//				q.pop();
//				if(ans.size()==(unsigned)map[tar]){
//					ans.push_back(vector<int>());
//				}
//				ans[map[tar]].push_back(tar->val);
//				if (tar->left != nullptr) {
//					q.push(tar->left);
//					map[tar->left] = map[tar] + 1;
//				}
//				if (tar->right != nullptr) {
//					q.push(tar->right);
//					map[tar->right] = map[tar] + 1;
//				}
//			}
//			return ans;
//		}
//};

//容器
//class Solution {
//	public:
//		vector<vector<int>> levelOrder(TreeNode* root) {
//			queue<TreeNode*>q;
//			vector<vector<int>>ans;
//			if (root == nullptr) {
//				return ans;
//			}
//			q.push(root);
//
//			while (!q.empty()) {
//				unsigned int t = q.size();
//				vector<int> m;
//				for (unsigned int i = 0; i < t; i++) {
//					TreeNode* tar = q.front();
//					m.push_back(tar->val);
//					if (tar->left != nullptr) {
//						q.push(tar->left);
//					}
//					if (tar->right != nullptr) {
//						q.push(tar->right);
//					}
//					q.pop();
//				}
//				ans.push_back(m);
//			}
//			return ans;
//		}
//};

//自建队列
const int MAXN = 2000;
TreeNode* arr[MAXN];
int l = 0;
int r = 0;
// [l ...r)
class Solution {
	public:
		vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> ans;
			if (root == nullptr) {
				return ans;
			}
			arr[r] = root;
			r++;
			while (l != r) {
				int t = r - l;
				vector<int>a;
				for (int i = 0; i < t; i++) {
					TreeNode* tar = arr[l];
					a.push_back(tar->val);
					if (tar->left != nullptr) {
						arr[r++] = tar->left;
					}
					if (tar->right != nullptr) {
						arr[r++] = tar->right;
					}
					l++;
				}
				ans.push_back(a);
			}
			return ans;
		}
};
int main() {
	vector<int>a;
	a[0] = 1;  //错误！直接越界了！
	cout << a[0];
	return 0;
}
