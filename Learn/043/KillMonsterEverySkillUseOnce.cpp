#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int n; // n个技能
int m;//怪兽一个m滴血
const int MAXN = 10;
int boold[MAXN];//每一个技能双倍输出的血量
int kill[MAXN];//每一个技能的普通输出

/**
 * 这题根据数据量采取了暴力递归的方式
 * 这个全排列的时间复杂度n!
 * 10*n!的结果是可以接受的
 */
//全排列 m为当前血量
int solve(int i, int m) {
	if (m <= 0) {
		return i ;
	}

	if (i == n) {
		return numeric_limits<int>::max();  //最后一招打完了
	}

	int ans = numeric_limits<int>::max();

	for (int j = i ; j < n; j++) {
		swap(boold[j], boold[i]);
		swap(kill[i], kill[j]);
		ans = min(solve(i + 1, ( m <= boold[i] ? m - 2 * kill[i] : m - kill[i])), ans);
		swap(boold[j], boold[i]);
		swap(kill[i], kill[j]);
	}
	return ans;

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> kill[i] >> boold[i];
		}
		int ans = solve(0, m);
		if (ans == numeric_limits<int>::max()) {
			ans = -1;
		}
		cout << ans << "\n";
	}
}
// 64 位输出请用 printf("%lld")
