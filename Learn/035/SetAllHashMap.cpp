#include <iostream>
#include <unordered_map>
#include <array>
using namespace std;


class HX {
	public:
		unordered_map<int, array<int, 2>> m;
		int cnt;
		int setAllTime;
		int setAllValue;
		HX() {
			cnt = 0;
			setAllTime = -1;
		}
		void put(int key, int value) {
			if (m.count(key)) {
				m[key][0] = value; //值
				m[key][1] = cnt++; //加入时间
			} else {
				m[key] = array<int, 2> {value, cnt++};
			}
		}

		int query(int key) {
			if (m.count(key)) {
				if (m[key][1] > setAllTime) {
					return m[key][0];
				} else {
					return setAllValue;
				}
			} else {
				return -1;
			}
		}

		void setAll(int value) {
			setAllTime = cnt++;
			setAllValue = value;
		}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	HX a = HX();
	int n, o, key, value;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> o;
		if (o == 1) {
			cin >> key >> value;
			a.put(key, value);
		} else if (o == 2) {
			cin >> key;
			cout << a.query(key) << "\n";
		} else {
			cin >> value;
			a.setAll(value);
		}
	}
	return 0;
}
// 64 位输出请用 printf("%lld")
