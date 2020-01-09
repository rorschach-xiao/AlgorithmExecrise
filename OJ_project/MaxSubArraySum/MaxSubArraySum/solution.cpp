#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) { //O(n)
		int size = nums.size();
		vector<int> opt(size + 1);
		opt[0] = 0;
		int MaxSubArraySum = nums[0];
		for (int i = 1; i <= size; i++) {
			opt[i] = (opt[i - 1] + nums[i - 1]) > nums[i - 1] ? (opt[i - 1] + nums[i - 1]) : nums[i - 1];
		}
		for (int i = 1; i <= size; i++) {
			if (opt[i] > MaxSubArraySum)
				MaxSubArraySum = opt[i];
		}
		return MaxSubArraySum;
	}

};
int main(){
	int a[] = { -2,1 };
	vector<int> nums(a, a + 2);
	Solution solution;
	cout << solution.maxSubArray(nums)<<endl;
	return 0;
}