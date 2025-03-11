#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


/**
 * a/b向上取整：(a+b-1)/b
 * a=b*k+c   如果c==0,返回k;如果c!=0,返回k+1,0<c<b
 * 推导过程
 * b*k+c+b-1=(k+1)*b+c-1
 * (a+b-1)/c = ((k+1)*b+c-1)/b
 */
class Bitset {
private:
	int* arr;
	bool reverse;
	int ones;
	int n;
public:
	Bitset(int size) {
		n = size;
		arr = new int[(size + 31) / 32];
//			fill(arr,arr+(size + 31) / 32,0);
		reverse = false;
		ones = 0;
	}

	//置1
	void fix(int idx) {
		int index = idx / 32;
		int bit = idx % 32;
		if (!reverse) {
			if ((arr[index] & (1 << bit)) == 0) {
				ones++;
				arr[index] |= (1 << bit);
			}
		} else {
			if ((arr[index] & (1 << bit)) != 0) {
				ones++;
				arr[index] ^= (1 << bit);
			}
		}
	}

	void unfix(int idx) {
		int index = idx / 32;
		int bit = idx % 32;
		if (!reverse) {
			if ((arr[index] & (1 << bit)) != 0) {
				ones--;
				arr[index] ^= (1 << bit);
			}
		} else {
			if ((arr[index] & (1 << bit)) == 0) {
				ones--;
				arr[index] ^= (1 << bit);
			}
		}
	}

	void flip() {
		reverse = ! reverse;
		ones = n - ones;
	}

	bool all() {
//		cout << "ones=" << ones << ",n=" << n << "\n";
		return ones == n;
	}

	bool one() {
		return ones != 0;
	}

	int count() {
		return ones;
	}

	string toString() {
		string res;
		for (int k = 0, i = 0; k < (n + 31) / 32 && i < n; k++) {
			int num = arr[k];
			for (int j = 0; j < 32 && i < n; i++, j++) {
				int status = num & (1 << j);
				status = !reverse ? status : !status;
				string a = status == 0 ? "0" : "1";
				res.append(a);
			}
		}
		return res;
	}
};
int main() {
	Bitset b = Bitset(5);
	cout << b.toString() << "\n";
	b.fix(3);
	cout << b.toString() << "\n";
	b.fix(1);
	cout << b.toString() << "\n";
	b.flip();
	cout << b.toString() << "\n";
	cout << b.all() << "\n";
	b.unfix(0);
	cout << b.toString() << "\n";
	b.flip();
	cout << b.toString() << "\n";
	cout<<b.one()<<"\n";
	b.unfix(0);
	cout << b.toString() << "\n";
	cout<<b.count()<<"\n";
	cout << b.toString() << "\n";
}
/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
