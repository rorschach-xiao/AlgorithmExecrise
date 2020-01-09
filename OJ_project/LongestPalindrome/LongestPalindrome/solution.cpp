#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

	string longestPalindrome(string s) {
		int start_max = 0, end_max = 0;
		int max_len = 0;
		vector<vector<bool>> IsPalindrome(s.length(), vector<bool>(s.length()));

		for (int len = 1; len <= s.length(); len++) {
			for (int start = 0; start < s.length(); start++) {
				int end = start + len - 1;
				if (end > s.length() - 1)
					break;
				if (len == 1) {
					IsPalindrome[start][end] = true;
				}
				else if (len == 2) {
					IsPalindrome[start][end] = (s[start] == s[end]);
				}
				else {
					IsPalindrome[start][end] = IsPalindrome[start + 1][end - 1] && s[start] == s[end];
				}
				if (IsPalindrome[start][end] && len > max_len) {
					start_max = start;
					end_max = end;
					max_len = len;
				}
			}
		}
		return s.substr(start_max, max_len);
	}
};
int main() {
	Solution s;
	string str = "ababc";

	cout << s.longestPalindrome(str).c_str() << endl;
	system("pause");
	return 0;
}