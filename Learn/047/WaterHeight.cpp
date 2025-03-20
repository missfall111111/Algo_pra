#include <iostream>

/**
 *
  对于 100% 的数据，n<=10
  6
  ,m<=10
  6
  ,1<=v<=10000,1<=x<=m
 */
using namespace std;

int m; //湖泊的宽度
int n; //朋友的数目
int v; //朋友的体积
int x; //朋友的入水点
const int MAXM = 1e6 + 10;

const int offset = 3 * 10000;
int height[MAXM + 1 + 2 + 2 * offset];
void compute(int l, int r, int s, int e, int d) {
	height[l] += s;
	height[l + 1] += d - s;
	height[r + 1] -= e + d;
	height[r + 2] += e;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;

	while (n--) {
		cin >> v >> x;
		compute(offset + x + 1, offset + x + 2 * v, -v + 1, v, 1);
		compute(offset + x - 2 * v + 1, offset + x, v - 1, -v, -1);
		compute(offset + x + 2 * v + 1, offset + x + 3 * v - 1, v - 1, 1, -1);
		compute(offset + x - 3 * v + 1, offset + x - 2 * v, 1, v, 1);
	}
	for (int i =  1; i <= offset + m; i++) {
		height[i] += height[i - 1];
	}
	for (int i = 1; i <= offset + m; i++) {
		height[i] += height[i - 1];
	}
	for (int i = offset + 1; i <= offset + m; i++) {
		cout << height[i] << " ";
	}
	return 0;
}
