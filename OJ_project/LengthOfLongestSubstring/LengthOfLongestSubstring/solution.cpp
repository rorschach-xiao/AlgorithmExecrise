#include<iostream>
#include<vector>
using namespace std;
class LengthOfLongestSubstring {
public:
	int lengthOfLongestSubstring(string s) {
		int total_len = s.length();
		int max_len=1;
		vector<int> opt(total_len);
		for (int i = 0; i < total_len; i++) {
			if (i == 0) {
				opt[i] = 1;
			}
			else {
				int j;
				for(j=1;j<=opt[i-1]&&s[i-j]!=s[i];j++){}
				if (j == opt[i-1]+1) {
					opt[i] = opt[i - 1] + 1;
				}
				else {

					opt[i] = j;
				}
				if (max_len < opt[i])
					max_len = opt[i];
			}
		}
	
		return max_len;
	}
};
int main(){
	string s = "b";
	LengthOfLongestSubstring solution;
	cout << solution.lengthOfLongestSubstring(s) << endl;
	system("pause");
	return 0;
}