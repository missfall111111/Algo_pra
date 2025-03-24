#include <vector>

using namespace std;


//grid是一个二维数组
//要返回其中最大的被1环绕的正方形的面积
class Solution {
	public:
		//判断该点为左上角 目标为target长的边 是否存在

		//计算(i1,j1)左上角到(i2,j2)右下角之间的前缀和
		//注意，这里的i,j是相对于grid ,prefixSum需要变换
		int calSum(const vector<vector<int>>&prefixSum, const int &i1, const int &j1, const int& i2, const int &j2) {
			if (i2 < i1) {
				return 0;
			}
			return prefixSum[i2 + 1][j2 + 1]
			       - prefixSum[i1][j2 + 1]
			       - prefixSum[i2 + 1][j1]
			       + prefixSum[i1][j1];
		}

		//计算那个点为左上角，及其右下角的点之间的二维前缀和
		//减去左上角的右下角和右上角的左上角两点之间的前缀和
		//之差是否是边长
		bool check(const vector<vector<int>> &grid, const int &i, const int &j, int& tar, const vector<vector<int>>&prefixSum) {
			//右下角的点
			int i2 = i + tar - 1;
			int j2 = j + tar - 1;
			//右下角不存在
			if (i2 >= (int)grid.size() || j2 >= (int)grid[0].size()) {
				return false;
			}

			//s是外边一圈的和
			int s = calSum(prefixSum, i, j, i2, j2) - calSum(prefixSum, i + 1, j + 1, i2 - 1, j2 - 1);

			//tar>=2
			return s == 4 + (tar - 2) * 4;
		}


		//返回二维数组中被1环绕的最大范围的面积，至少为1
		int explore(const vector<vector<int>>&grid, const vector<vector<int>>&prefixSum) {

			//遍历每一个元素，其为左上角顶点，能围成正方形的最大边长是什么？
			//边长从1开始 大于bian有就更新并一直贪心，没有就去下一个

			//存在一个点对于较小的tar不行，但是对于较大的tar可以的

			int ans = 1;
			for (unsigned int i = 0; i < grid.size(); i++) {
				for (unsigned int j = 0; j < grid[0].size(); j++) {
					int tar = ans + 1;
					//判断该点为左上角 目标为target长的边 是否存在？存在就更新并再次重复，不存在就下一个
					//tar-1是（0，0）为左上角，tar为边长，的右上角和左下角的位置索引
					while (tar - 1 < (int)min(grid.size(), grid[0].size())) {
						if (check(grid, i, j, tar, prefixSum)) {
							ans = tar;
						}
						tar++;
					}
				}
			}
			//返回最大的边长
			return ans;
		}

		int largest1BorderedSquare(vector<vector<int>>& grid) {
			//处理边界情况 全是0
			int s = 0;
			for (const auto &arr : grid) {
				for (const auto &e : arr) {
					s += e;
				}
			}
			if (s == 0) {
				return 0;
			}


			//否则至少为1
			int ans = 1;

			//构造前缀和，用于判断
			vector<vector<int>>prefixSum(grid.size() + 1, vector<int>(grid[0].size() + 1));

			for (unsigned int i = 0; i < grid.size(); i++) {
				for (unsigned int j = 0; j < grid[0].size(); j++) {
					prefixSum[i + 1][j + 1] = grid[i][j]
					                          + prefixSum[i + 1][j]
					                          + prefixSum[i][j + 1]
					                          - prefixSum[i][j];
				}
			}


			ans = explore(grid, prefixSum);
			return ans * ans;
		}
};
