#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 999999
class MaximumNumberOfUsers {
public:
	long max_num;
	int min_prices;
	MaximumNumberOfUsers();
	~MaximumNumberOfUsers();

	void GetMaximumUsers(vector<int> &tasks, vector<vector<vector<long>>> &opt, int M, int N) {
			for (int j = tasks[0]; j < M +1 ; j++) {
				for (int k = tasks[1]; k < N + 1; k++) {
						opt[1][j][k] = max(opt[0][j - tasks[0]][k - tasks[1]] + tasks[2], opt[0][j][k]);
				}
			}
			opt[0].assign(opt[1].begin(), opt[1].end());
		max_num= opt[1][M][N];
	}
	void GetMinmumPrice(vector<vector<int>> &tasks, int M, int N) {
		int n = tasks.size();
		int p_sum = 0, x_sum = 0, y_sum = 0;

		vector<vector<vector<int>>> opt(n, vector<vector<int>>(M, vector<int>(N, INF)));
		for (int i = 0; i < n; i++) {
			opt[i][0][0] = 0;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < N; k++) {
					if (j - tasks[i][0] >= 0 && k - tasks[i][1] >= 0) {
						opt[i][j][k] = min(opt[i - 1][j - tasks[i][0]][k - tasks[i][1]] + tasks[i][2], opt[i - 1][j][k]);
					}
					else {
						opt[i][j][k] = min(opt[i - 1][(j - tasks[i][0]) < 0 ? 0 : (j - tasks[i][0])][(k - tasks[i][1]) < 0 ? 0 : (k - tasks[i][1])] + tasks[i][2], opt[i - 1][j][k]);
					}
				}
			}
		}
		min_prices= opt[n - 1][M - 1][N - 1];
	}
};
MaximumNumberOfUsers::MaximumNumberOfUsers() {}
MaximumNumberOfUsers::~MaximumNumberOfUsers() {}
int main(){
	//int d0[3] = { 0,0,0 };
	//int d1[3] = { 3,36,120 };
	//int d2[3] = { 10,25,129 };
	//int d3[3] = { 5,50,250 };
	//int d4[3] = { 1,45,130 };
	//int d5[3] = { 4,20,119 };
	//vector<vector<int>> v(6, vector<int>());
	//v[0].insert(v[0].begin(), &d0[0], &d0[2] + 1);
	//v[1].insert(v[1].begin(), &d1[0], &d1[2] + 1);
	//v[2].insert(v[2].begin(), &d2[0], &d2[2] + 1);
	//v[3].insert(v[3].begin(), &d3[0], &d3[2] + 1);
	//v[4].insert(v[4].begin(), &d4[0], &d4[2] + 1);
	//v[5].insert(v[5].begin(), &d5[0], &d5[2] + 1);

    /*Input sample     
	 15 10 4
	 5 1 1000
	 2 3 3000
	 5 2 15000
	 10 4 16000
	 output sample
	 31000
	*/
	int M, N, K;
	scanf_s("%d %d %d", &M, &N, &K);
	vector<int> v;
	vector<vector<vector<long>>> opt(2, vector<vector<long>>(M + 1, vector<long>(N + 1, 0)));
	MaximumNumberOfUsers s;


	for (int i = 0; i < K; i++) {
		int x, y, p;
		vector<int> temp;
		scanf_s("%d %d %d", &x, &y, &p);
		temp.push_back(x);
		temp.push_back(y);
		temp.push_back(p);
		s.GetMaximumUsers(temp, opt, M, N);
		vector<int>().swap(temp);
	}
	cout << s.max_num<< endl;
	system("pause");
	return 0;

}