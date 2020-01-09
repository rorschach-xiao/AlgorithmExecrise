#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class RobbingMoney {
public:
	RobbingMoney();
	~RobbingMoney();

	long long MaxRobbingMoney(vector<long long> &v) {
		int n = v.size();
		vector<long long> opt(n, 0);
		if (n == 0)
			return 0;
		else if (n == 1) {
			return v[0];
		}
		else if (n == 2) {
			return v[0] > v[1] ? v[0] : v[1];
		}
		opt[0] = v[0];
		opt[1] = v[0] > v[1] ? v[0] : v[1];
		for (int i = 2; i < n; i++) {
			opt[i] = max(opt[i - 1], opt[i - 2] + v[i]);
		}
		return opt[n - 1];
	}
};
RobbingMoney::RobbingMoney(){}
RobbingMoney::~RobbingMoney(){}

int main() {
	vector<long long> v;
	long long temp;
	while (cin >> temp) {
		v.push_back(temp);
	}
	RobbingMoney s;
	cout << s.MaxRobbingMoney(v) << endl;
	return 0;
}