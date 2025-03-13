#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int MAXN = 3 * 100000;
int nodePath[MAXN][26];
int pass[MAXN];
int cnt;
string res[MAXN];
class Solution {
	public:
		int explore(vector<vector<char>> board, unsigned int i, unsigned int j, int node, vector<string>&ans) {

			//越界  或者是来时的轨迹
			if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 0) {
				return 0;
			}

			char c = board[i][j];
			int path = c - 'a';

			node = nodePath[node][path];
			//没有那个单词,或者已经被搜索过了
			if (pass[node] == 0) {
				return 0;
			}

			int fix = 0;
			if (res[node] != "") {
				fix++;
				ans.push_back(res[node]);
				res[node] = "";
			}

			board[i][j] = 0;
			fix += explore(board, i - 1, j, node, ans);
			fix += explore(board, i, j - 1, node, ans);
			fix += explore(board, i + 1, j, node, ans);
			fix += explore(board, i, j + 1, node, ans);

			pass[node] -= fix;
			board[i][j] = c;
			return fix;
		}

		void insert(const string &word) {
			int cur = 1;
			for (const auto &ele : word) {
				pass[cur]++;
				int path = ele - 'a';
				if (nodePath[cur][path] == 0) {
					nodePath[cur][path] = ++cnt;
				}
				cur = nodePath[cur][path];
			}
			pass[cur]++;
			res[cur] = word;
		}

		void build(vector<string>&words) {
			for (const auto &word : words) {
				insert(word);
			}
		}

		void clear() {
			cnt = 0;
			for (int i = 0; i < MAXN; i++) {
				pass[i] = 0;
				res[i] = "";
				for (int j = 0; j < 26; j++) {
					nodePath[i][j] = 0;
				}
			}
		}
		vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
			//先建立起前缀树
			cnt = 1;
			build(words);
			//对矩阵里的每一个单词进行搜索
			vector<string>ans;
			for (unsigned int i = 0; i < board.size(); i++) {
				for (unsigned int j = 0; j < board[i].size(); j++) {
					explore(board, i, j, 1, ans);
				}
			}
			clear();
			return ans;
		}
};


int main() {
	vector<vector<char>>board = {{'a', 'a'}};
	Solution s;
	vector<string>words = {"aaa"};
	vector<string>res = s.findWords(board, words);
	for (const auto &ele : res) {
		cout << ele << "\n";
	}
	return 0;
}
