#include <vector>
#include <algorithm>
using namespace std;


class Solution {
	public:

		long sort1(vector<long>&a, long size) {
			sort(a.begin(), a.end());
			long s = 1;
			for (long i = 1; i < size; i++) {
				if (a[i] != a[i - 1]) {
					a[s++] = a[i];
				}
			}
			return s;
		}

		long getIndex(vector<long>&a, long s, long v) {
			long l = 0;
			long r = s - 1;
			long m, ans = 0;
			while (l <= r) {
				m = (l + r) / 2;
				if (a[m] >= v) {
					ans = m;
					r = m - 1;
				} else {
					l = m + 1;
				}
			}

			return ans + 1;
		}

		int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {

			const long n = forceField.size();

//			long xs[n * 2] = {};
//			long ys [n * 2] = {};
			vector<long>xs(n * 2);
			vector<long>ys(n * 2);
			long i = 0, j = 0;
			//先计算出每一个立场的左右x边界  和上下y边界 存在 xs ys里
			//是转换后的
			for (const auto&arr : forceField) {
				long x = arr[0];
				long y = arr[1];
				long r = arr[2];

				xs[i++] = (x << 1) - r;
				xs[i++] = (x << 1) + r;
				ys[j++] = (y << 1) - r;
				ys[j++] = (y << 1) + r;
			}

			long sizex = sort1(xs, n * 2);
			long sizey = sort1(ys, n * 2);

//			long diff[sizex + 2][sizey + 2] = {};
			vector<vector<long>>diff(sizex + 2, vector<long>(sizey + 2));

			for (long i = 0, a, b, c, d; i < n; i++) {
				long x = forceField[i][0];
				long y = forceField[i][1];
				long r = forceField[i][2];

				a = getIndex(xs, sizex, (x << 1) - r);
				b = getIndex(ys, sizey, (y << 1) - r);
				c = getIndex(xs, sizex, (x << 1) + r);
				d = getIndex(ys, sizey, (y << 1) + r);

				diff[a][b] += 1;
				diff[c + 1][d + 1] += 1;
				diff[c + 1][b] -= 1;
				diff[a][d + 1] -= 1;
			}

			long ans = 0;
			for (long i = 1; i <= sizex; i++) {
				for (long j = 1; j <= sizey; j++) {
					diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
					ans = max(ans, diff[i][j]);
				}
			}
			return ans;
		}
};
