#include <vector>

using namespace std;


class Solution {
	public:


		//i1 j2   i2 j2是相对于grid而言的
		bool check(vector<vector<int>>&grid,  vector<vector<int>>&prefixSum,  int i1, int j1, int i2, int j2) {

			if (i2 >= (int) grid.size() || j2 >= (int) grid[0].size()) {
				return false;
			}
			return prefixSum[i2 + 1][j2 + 1]
			       - prefixSum[i1][j2 + 1]
			       - prefixSum[i2 + 1][j1]
			       + prefixSum[i1][j1] == 0;
		}


		//i1 j2   i2 j2是相对于grid而言的
		void add(vector < vector<int>>&diff, int i1, int j1, int i2, int j2, int val) {
			diff[i1 + 1][j1 + 1] += 1;
			diff[i1 + 1][j2 + 2] -= 1;
			diff[i2 + 2][j1 + 1] -= 1;
			diff[i2 + 2][j2 + 2] += 1;
		}

		bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
			vector<vector<int>>diff(grid.size() + 2, vector<int>(grid[0].size() + 2));

			vector<vector<int>>prefixSum(grid.size() + 1, vector<int>(grid[0].size() + 1));
			//制造前缀和

			for (unsigned int i = 0; i < grid.size(); i++) {
				for (unsigned int j = 0; j < grid[0].size(); j++) {
					prefixSum[i + 1][j + 1] = grid[i][j] +
					                          prefixSum[i + 1][j] +
					                          prefixSum[i][j + 1] -
					                          prefixSum[i][j];
				}
			}

			for (unsigned int i = 0; i < grid.size(); i++) {
				for (unsigned int j = 0; j < grid[0].size(); j++) {
					//首先先找到grid里所有为0的位置为左上角
					if (grid[i][j] == 0) {
						//看看能不能贴
						if (check(grid, prefixSum, i, j, i + stampHeight - 1, j + stampWidth - 1)) {
							//能贴就贴 =》 在差分数组里整体加
							add(diff, i, j, i + stampHeight - 1, j + stampWidth - 1, 1);
						}
						//不能贴就下一个
					}
				}
			}

			//build
			for (unsigned int i = 1; i <= grid.size(); i++) {
				for (unsigned int j = 1; j <= grid[0].size(); j++) {
					diff[i][j] += diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
				}
			}

			//最后看看源数组为0的地方，差分数组是不是>0?

			for (unsigned int i = 0; i < grid.size(); i++) {
				for (unsigned int j = 0; j < grid[0].size(); j++) {
					if (grid[i][j] == 0 && diff[i + 1][j + 1] == 0) {
						return false;
					}
				}
			}

			return true;
		}
};
