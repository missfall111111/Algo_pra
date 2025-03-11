#include<iostream>
#include<vector>
#include<stack>
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
		vector<int> preorderTraversal(TreeNode* root) {
			stack<TreeNode*> s;
			vector<int>res;
			if(!root){
				return res;
			}
			TreeNode * cur=root;
			
			s.push(cur);
			while(!s.empty()){
				res.push_back(cur->val);
				s.pop();
				if(cur->right){
					s.push(cur->right);
				}
				if(cur->left){
					s.push(cur->left);
				}
				if(!s.empty()){
					cur=s.top();
				}
			}
			
			return res;
		}
};
