#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class LCS {
public:

	vector<vector<int>> arrow; //use for back tracking , 0 represent diagonalize ,1 represent upward , 2 represent leftward
	int LCS_len;

	LCS();
	~LCS();

	void GetLCS(string &s, string &t);
	void SpaceOptimal_GetLCS(string &s, string &t);
	void TimeOptimal_GetLCS(string &s, string &t);
	string BackTracking(vector<vector<int>> arrow,string &s,string &t);
};
LCS::LCS() {
}
LCS::~LCS() {
	vector<vector<int>>().swap(arrow);
}
void LCS::GetLCS(string &s, string &t) { //time complexity O(n^2),space complexity O(n^2)
	int ls = s.length();
	int lt = t.length();
	vector<vector<int>> opt(ls+1, vector<int>(lt+1, 0));
	vector<vector<int>> arr(ls + 1, vector<int>(lt + 1, -1));//use for back tracking , 0 represent diagonalize ,1 represent upward , 2 represent leftward
	for (int i = 1,n=0; i <=ls; n++,i++) {
		for (int j = 1,m=0; j <= lt;m++,j++) {
			if (s[n] == t[m]) {
				opt[i][j] = opt[i - 1][j - 1] + 1;
				arr[i][j]=0;
			}
			else {
				opt[i][j] = max(opt[i][j - 1], opt[i - 1][j]);
				if (opt[i][j - 1] > opt[i - 1][j]) {
					arr[i][j]=2;
				}
				else {
					arr[i][j]=1;
				}
			}
		}
	}
	arrow.swap(arr);
	LCS_len = opt[ls][lt];
}
void LCS::SpaceOptimal_GetLCS(string &s, string &t) { // time complexity is O(n)
	int ls = s.length();
	int lt = t.length();
	vector<int> opt(lt + 1, 0);
	int last, cur;
	for (int i = 1; i <= ls; i++) {
		last = 0;
		for (int j = 1; j <= lt; j++) {
			cur = opt[j];
			if (s[i - 1] == t[j - 1]) {
				opt[j] = last + 1;
			}
			else {
				opt[j] = max(cur, opt[j - 1]);
			}
			last = cur;
		}
	}
	LCS_len = opt[lt];
}
string LCS::BackTracking(vector<vector<int>> arrow, string &s, string &t) {
	int ptr1 = s.length()-1;
	int ptr2 = t.length()-1;
	vector<char> result;
	string lcs;
	int i = arrow.size() - 1;
	int j = j = arrow[0].size() - 1;
	while(i!=0 &&j!=0 && arrow[i][j]!=-1){
		if (arrow[i][j] == 0) {
			result.push_back(s[ptr1]);
			i--;
			j--;
			ptr1--;
			ptr2--;
		}
		else if (arrow[i][j] == 1) {
			ptr1--;
			i--;
		}
		else {
			ptr2--;
			j--;
		}
	}
	for (int i = 0; i < LCS_len; i++) {
		lcs.append(1,result.back());
		result.pop_back();
	}
	return lcs;
}
void LCS::TimeOptimal_GetLCS(string &s,string &t){
	int ls = s.length();
	int lt = t.length();
	int len = 1;
	vector<vector<int>> a(26,vector<int>());
	vector<int> s2;
	vector<int> low;
	for (int i = 0; i < lt; i++) { //O(n) 扫描整个t串，记录每个字符出现的位置
		a[t[i] - 'A'].push_back(i);
	}
	for (int i = 0; i < ls; i++) { //O(m)~O(mn) 将s中每个字符替换成其在t中出现的位置，记录在新的数组s2中
		if (a[s[i]-'A'].size() != 0) {
			for (int j = a[s[i] - 'A'].size() - 1; j >= 0; j--) {
				s2.push_back(a[s[i] - 'A'][j]);
			}
		}
	}
	if (s2.size() == 0) {
		LCS_len = 0;
		return;
	}
	else {
		low.push_back(s2[0]);
		for (int i = 1; i < s2.size(); i++) { // O(m)
			if (s2[i] > low[len - 1]) {
				low.push_back(s2[i]);
				len++;
			}
			else {
				int l = 0, r = len - 1;
				while (l < r) { // 用二分法找到low中第一个比s2[i]大的位置 O（logn）
					int mid = (l + r) >> 1;
					if (low[mid] >= s2[i]) {
						r = mid;
					}
					else {
						l = mid + 1;
					}
				}
				low[l] = s2[i];

			}
		}
		LCS_len = len;
	}
}
int main() {
	LCS lcs;
	int N;
	cin >> N;
	vector<int> result;
	for (int i = 0; i < N; i++) {
		int len_s, len_t;
		cin >> len_s >> len_t;
		string A;
		string B;
		for (int j = 0; j < len_s; j++) {
			char c;
			cin >> c;
			A.append(1,c);
		}

		for (int j = 0; j < len_t; j++) {
			char c;
			cin >> c;
			B.append(1,c);
		}
		lcs.TimeOptimal_GetLCS(A, B);
		result.push_back(lcs.LCS_len);
	}
	for (int i = 0; i < N; i++) {
			cout << result[i] << endl;
	}
	//string A="aaaaaa";
	//string B="aaaaaa";
	//getline(cin, A);
	//getline(cin, B);
	
	//lcs.GetLCS(A, B);
	//lcs.SpaceOptimal_GetLCS(A, B);
	//lcs.TimeOptimal_GetLCS(A, B);
	//cout << lcs.LCS_len << endl;
	//cout << lcs.BackTracking(lcs.arrow, A, B) << endl;
	system("pause");
}