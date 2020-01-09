#include<iostream>
#include<vector>
using namespace std;
class SearchPivotArray {
public:
	int search(vector<int>& nums, int target) {
		int size = nums.size();
		if (size == 0) return -1;
		return divide_search(nums, 0, size - 1, target);
	}
	int divide_search(vector<int>& nums, int left, int right, int target) {
		if (left == right) {
			return target == nums[left] ? left : -1;
		}
		if (right < left) return -1;
		int mid = (left + right) >> 1;
		if (nums[mid] == target) return mid;
		if (nums[mid] < nums[right]) {
			if (nums[mid] > target || target>nums[right])
				return divide_search(nums, left, mid - 1, target);
			else
				return divide_search(nums, mid + 1, right, target);

		}
		else {
			if(target>nums[mid] || target<nums[left])
				return divide_search(nums, mid + 1, right, target);
			else
				return divide_search(nums, left, mid - 1, target);
		}

	}
};
int main() {
	int a[] = {1,3 };
	vector<int> arr(a, a + 2);
	SearchPivotArray solution;
	cout << solution.search(arr, 0) << endl;
	system("pause");
	return 0;
}