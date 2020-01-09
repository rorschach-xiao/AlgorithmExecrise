#include<iostream>
#include<vector>
using namespace std;
class SumOfThreeNums {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int size = nums.size();
		vector<vector<int>> result;
		if (size == 0)
			return result;
		MergeSort(nums, 0, size-1);
		int last_key = nums[0];
		for (int i = 0; i < size; i++) {
			int p1 = i + 1, p2 = size - 1;//p1 p2 分别指向第i个数后的头和尾
			if(i>0&&nums[i]==nums[i-1]){
				continue;
			}
			if (nums[i] > 0)
				break;
			while (p1 < p2) {
				if (nums[p1] + nums[p2] == -nums[i]) {
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[p1]);
					temp.push_back(nums[p2]);
					result.push_back(temp);
					vector<int>().swap(temp);
					p2--;
					while (p2 > p1 && nums[p2] == nums[p2 + 1]) { p2--; }
					p1++;
					while (p2 > p1 && nums[p1] == nums[p1 - 1]) { p1++; }
				}
				else if (nums[p1] + nums[p2] > -nums[i]) {
					p2--;
				}
				else if (nums[p1] + nums[p2] < -nums[i]) {
					p1++;
				}
			}

		}
		return result;
	}
	void MergeSort(vector<int>& v, int left, int right) {
		if (left == right)
			return;
		else {
			int mid = (left + right) >> 1;
			MergeSort(v, left, mid);
			MergeSort(v, mid+1, right);
			Merge(v, left, right, mid);
		}
	}
	void Merge(vector<int>& v, int left, int right, int mid) {
		vector<int> result;
		int i = left, j = mid+1;
		while (i <= mid&&j <= right) {
			result.push_back(v[i] < v[j] ? v[i++] : v[j++]);
		}
		while (i <= mid) {
			result.push_back(v[i++]);
		}
		while (j <= right) {
			result.push_back(v[j++]);
		}
		for (int i = left; i <= right; i++) {
			v[i] = result[i - left];
		}
	}
};
int main(){
	int a[] = {-2,0,0,2,2};
	vector<int> nums(a,a+5);
	vector<vector<int>> result;

	SumOfThreeNums solution;
	result=solution.threeSum(nums);
	system("pause");
	return 0;
}