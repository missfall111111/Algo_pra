#include<queue>
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
		bool isCompleteTree(TreeNode* root) {
			if(root==nullptr){
				return true;
			}
			bool leaf=false;
			queue<TreeNode*>q;
			q.push(root);
			while(!q.empty()){
				TreeNode* head=q.front();
				if((head->left==nullptr&&head->right!=nullptr) || (leaf&&(head->left!=nullptr||head->right!=nullptr))){
					return false;
				}
				
				if(head->left!=nullptr){
					q.push(head->left);
				}
				if(head->right!=nullptr){
					q.push(head->right);
				}
				
				if(head->left==nullptr || head->right==nullptr){
					leaf=true;
				}
				q.pop();
			}
			return true;
		}
};
