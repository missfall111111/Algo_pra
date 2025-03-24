#include <vector>

using namespace std;

//class NumMatrix {
//	public:
//
//		vector<vector<int>>PrefixSum;
//		NumMatrix(vector<vector<int>>& matrix) {
//			int col = matrix[0].size();
//			vector<int>tmp;
//			for (int i = 0; i < col + 1 ; i++) {
//				tmp.push_back(0);
//			}
//			PrefixSum.push_back(tmp);
//			tmp.clear();
//
//			for (unsigned int i = 0; i < matrix.size(); i++) {
//				// 每一行
//				tmp.push_back(0);
//				for (unsigned int j = 0; j < matrix[0].size(); j++) {
//					tmp.push_back(matrix[i][j] + tmp[j] + PrefixSum[i][j + 1] - PrefixSum[i ][j]);
//				}
//				PrefixSum.push_back(tmp);
//				tmp.clear();
//			}
//		}
//
//		int sumRegion(int row1, int col1, int row2, int col2) {
//			row1 += 1;
//			col1 += 1;
//			row2 += 1;
//			col2 += 1;
//
//			return PrefixSum[row2][col2] - PrefixSum[row1 - 1][col2] - PrefixSum[row2][col1 - 1] + PrefixSum[row1 - 1][col1 - 1];
//		}
//};
//
///**
// * Your NumMatrix object will be instantiated and called as such:
// * NumMatrix* obj = new NumMatrix(matrix);
// * int param_1 = obj->sumRegion(row1,col1,row2,col2);
// */
//
//int main() {
//	vector<vector<int>>matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
//	NumMatrix a = NumMatrix(matrix);
//	return 0;
//}

class NumMatrix {
	public:
		vector<vector<int>>prefixSum;
		NumMatrix(vector<vector<int>>& matrix) {
			int row = matrix.size();
			int col = matrix[0].size();
			prefixSum.resize(row + 1, vector<int>(col + 1));

			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					prefixSum[i + 1][j + 1] = matrix[i][j]
					                          + prefixSum[i + 1][j]
					                          + prefixSum[i][j + 1] - prefixSum[i][j];
				}
			}
		}

		int sumRegion(int row1, int col1, int row2, int col2) {
			return prefixSum[row2 + 1][col2 + 1]
			       - prefixSum[row1][col2 + 1]
			       - prefixSum[row2 + 1][col1 ]
			       + prefixSum[row1 ][col1 ];
		}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
