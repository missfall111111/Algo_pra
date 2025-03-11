#include <unordered_map>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
class RandomizedSet {
	public:
		unordered_map<int, int>map; //值，下标
		vector<int> arr;
		RandomizedSet() {
			srand(time(nullptr));
		}

		bool insert(int val) {
			if (map.count(val)) {
				return false;
			}
			map[val] = arr.size();
			arr.push_back(val);
			return true;
		}

		bool remove(int val) {
			if (!map.count(val)) {
				return false;
			}

			int endIndex = arr.size() - 1;
			arr[map[val]] = arr[endIndex];
			map[arr[endIndex]]=map[val];
			map.erase(val);
			arr.erase(arr.begin() + endIndex);
			return true;
		}

		int getRandom() {
			return arr[rand() % (arr.size())];
		}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
