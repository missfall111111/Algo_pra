#include <iostream>

using namespace std;

int n; //格子 nxn
int m; //m个地毯

const int MAXN = 1010;
int grid[MAXN][MAXN];  //格子 也是二维差分的地方

int x, y, x2, y2;

//对二维差分数组预备
void add(int x1, int y1, int x2, int y2, int v) {
	//x1+1 y1+1 x2+1 y2+1
	grid[x1 ][y1 ] += v;
	grid[x1 ][y2 + 1] -= v;
	grid[x2 + 1][y1 ] -= v;
	grid[x2 + 1][y2 + 1] += v;
}

//二维前缀和
void build() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			grid[i][j] = grid[i][j] + grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	while (m--) {
		cin >> x >> y >> x2 >> y2;
		add(x, y, x2, y2, 1);
	}

	build();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
