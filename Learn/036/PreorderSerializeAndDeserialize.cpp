#include <string>
#include<vector>
#include<sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//先序序列化
class Codec {
	public:
		void f(TreeNode*root, string &a) {
			if (root == nullptr) {
				a += "#,";
				return;
			}
			a += to_string(root->val)+",";
			f(root->left, a);
			f(root->right, a);
		}
		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {
			string res;
			f(root, res);
			return res;
		}

		int c;
		TreeNode* g(vector<string> data) {
			string a = "";
			a += data[c++];
			if (a == "#") {
				return nullptr;
			}
			TreeNode* newNode = new TreeNode(stoi(a));
			newNode->left = g(data);
			newNode->right = g(data);
			return newNode;
		}
		// Decodes your encoded data to tree.
		TreeNode* deserialize(string data) {
			c = 0;
			istringstream tokenstream(data);
			string token;
			vector<string>d;
			while(getline(tokenstream,token,',')){
				d.push_back(token);
			}
			return g(d);
		}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
