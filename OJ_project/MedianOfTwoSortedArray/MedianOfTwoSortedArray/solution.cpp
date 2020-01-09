#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int getKthElement(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
		int len1 = end1 - start1 + 1;
		int len2 = end2 - start2 + 1;
		if (len1 > len2)return getKthElement(nums2, start2, end2, nums1, start1, end1, k);
		if (len1 == 0) return nums2[start2 + k - 1];
		if (k == 1) return min(nums1[start1], nums2[start2]);
		
		int p1 = start1 + (len1 > (k / 2) ? (k / 2) : len1) - 1;
		int p2 = start2 + (len2 > (k / 2) ? (k / 2) : len2) - 1;
		if (nums1[p1] < nums2[p2]) {
			return getKthElement(nums1, p1+1, end1, nums2, start2, end2, k - (p1-start1)-1);
		}
		else {
			return getKthElement(nums1, start1, end1, nums2, p2+1, end2, k - (p2 - start2)-1);
		}


	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		return (getKthElement(nums1, 0, n - 1, nums2, 0, m - 1, (n + m + 1) / 2) + getKthElement(nums1, 0, n - 1, nums2, 0, m - 1, (n + m + 2) / 2))/2.0;
	}
};
int main() {
	vector<int> n1 = { 1,2 };
	vector<int> n2 = { 4,5,6,7 };
	Solution solution;
	cout << solution.findMedianSortedArrays(n1, n2) << endl;
	unsigned long *a = (unsigned long *)((0x4000000 >> 20) & 0xffc);
	unsigned long b = ((0x4000000 >> 20) & 0xffc);
	a++;
	b++;
	system("pause");
	return 0;
}