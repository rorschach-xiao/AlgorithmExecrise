#include<iostream>
#include<vector>
#include<string>
using namespace std;
class MonkeyEatBanana {
public:
	long int MaxBanana(vector<char> &s,int k) {
		int len = s.size();
		if (len == 0)return 0;
		long int count=0;
		vector<int> isvisited(len, 0);
		for (int i = 0; i < len; i++) {
			if (s[i] == 'M') {
				int j = i-1>0?i-1:0;
				int range = k-1>j?j:k-1;
				int find_flag = 0;
				while (j-range >= 0 && range>=0) {
					if (s[j-range] == 'B'&&isvisited[j-range]==0) {
						isvisited[j-range] = 1;
						find_flag = 1;
						count++;
						break;
					}
					range--;
				}
				if (find_flag == 0) {
					int j = i + 1<len?i+1:len-1;
					int range = k-1<len-j?k-1:len-1-j;
					while (j+range < len && range >= 0) {
						if (s[j+range] == 'B'&& isvisited[j+range]==0) {
							isvisited[j+range] = 1;
							count++;
							break;
						}
						range--;
					}
				}
			}
		}
		return count;
	}
};
int main() {
	string s;
	int k;
	getline(cin,s);
	scanf_s("%d", &k);
	vector<char> arr(s.c_str(),s.c_str()+s.size());
	MonkeyEatBanana solution;
	cout << solution.MaxBanana(arr, k) << endl;
	system("pause");
	return 0;
}