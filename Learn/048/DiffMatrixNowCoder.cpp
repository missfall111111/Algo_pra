#include <iostream>

using namespace std;

int m, n; //矩阵n行m列
int q;//q次操作

const int MAXN = 1010;
long diff[MAXN][MAXN];


//在x y为左上角 x2 y2为右下角的区域加v
void add(int x, int y, int x2, int y2, int v) {
	diff[x][y] += v;
	diff[x][y2 + 1] -= v;
	diff[x2 + 1][y] -= v;
	diff[x2 + 1][y2 + 1] += v;
}

void build() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			diff[i][j] += diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
		}
	}
}
int main() {

	cin >> n >> m >> q;

	//矩阵本来的信息
	for (int i = 1; i <= n; i++) {
		for (int j = 1, x; j <= m; j++) {
			cin >> x;
			add(i, j, i, j, x);
		}
	}

	//开始操作
	for (int i = 0, x1, y1, x2, y2, v; i < q; i++) {
		cin >> x1 >> y1 >> x2 >> y2 >> v;
		add(x1, y1, x2, y2, v);
	}

	build();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << diff[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
