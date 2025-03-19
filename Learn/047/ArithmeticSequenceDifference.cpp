#include <iostream>

using namespace std;

const int MAXN = 10000001;
int n; //n个柱子
int m; //m次攻击
int arr[MAXN + 1 + 2]; // 记录柱子的血量
//+1从1开始计数 同时算前缀和时不用考虑0位置的情况
//再+2是差分数组的r+1 r+2

//更新柱子被攻击后的血量状态 当然是差分数组的状态
//通过扩大数组容量避免边界讨论
void compute(int l, int r, int s, int e, int d) {
	arr[l] += s;
	arr[l + 1] += d - s;
	arr[r + 1] -= e + d;
	arr[r + 1] += e;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int l, r, s, e;
	cin >> n >> m;
	while (m--) {
		cin >> l >> r >> s >> e;
		int d = (e - s) / (r - l); //公差
		compute(l, r, s, e, d);

		for (int i = 1; i <= n; i++) {
			cout << arr[i] << " " << "\n";
		}
	}

	//从1开始 n结束
	for (int i = 1; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i];
	}
	for (int i = 1; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i];
	}

	int ma = arr[1];
	int exor = 0;

	for (int i = 1; i <= n; i++) {
		exor ^= arr[i];
		ma = arr[i] > ma ? arr[i] : ma;
	}

	cout << exor << " " << ma;

	return 0;
}
