#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 999999
class MaxProfitOfStock {
public:
	int MaxProfit_v1(vector<int> &prices) { //only one transaction is allowed
		int size = prices.size();
		if (size == 0)return 0;
		int max_price = 0, min_price = prices[0];
		for (int i = 1; i < size; i++) {
			int cur_max_profit = max(prices[i] - min_price, 0);
			if (prices[i] < min_price)
				min_price = prices[i];
			if (cur_max_profit > max_price)
				max_price = cur_max_profit;
		}
		return max_price;
	}
	long long MaxProfit_v2(vector<long long> &prices) {// no transaction limitation
		int size = prices.size();
		if (size == 0)return 0;
		long long result=0;
		for (int i = 1; i < size; i++) {
			result += prices[i] - prices[i - 1]>0?(prices[i]-prices[i-1]):0;
		}
		return result;
	}
	int MaxProfit_v3(vector<int> &prices) { //only two transactions are allowed
		int dp_i20 = 0, dp_i21 = -INF;
		int dp_i10 = 0, dp_i11 = -INF;
		for (vector<int>::iterator it = prices.begin(); it != prices.end(); ++it) {
			dp_i20 = max(dp_i20, dp_i21 + *it);
			dp_i21 = max(dp_i21, dp_i10 - *it);
			dp_i10 = max(dp_i10, dp_i11 + *it);
			dp_i11 = max(dp_i11, -*it);
		}
		return dp_i20;
	}
};
int main() {;
	vector<long long> p;
	long long temp;
	while (cin>>temp) {
		p.push_back(temp);
	}
	MaxProfitOfStock solution;
	cout << solution.MaxProfit_v2(p) << endl;
	system("pause");
	return 0;
}