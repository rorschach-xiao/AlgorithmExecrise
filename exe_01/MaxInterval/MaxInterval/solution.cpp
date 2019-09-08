#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;
class MaxInterval {
public:
	int NumberOfElement;
	vector<double> L;
	double MaxGap;
	double max, min;
	struct Bucket {
		double maxx = -INFINITY;
		double minx = INFINITY;
		int number = 0;
	};
	MaxInterval(const string& filename);
	~MaxInterval();

	double CaluculateMaxInterval(int N,vector<double> &L);
};
MaxInterval::MaxInterval(const string& filename) {
	ifstream input(filename, ios::in);
	char a[1000];
	double cur;
	if (!input) {
		cout << "can't open the file" << endl;
		return ;
	}
	input.getline(a, sizeof(a));
	stringstream num(a);
	num >> NumberOfElement;
	input.getline(a, sizeof(a));
	stringstream list(a);
	for (int i = 0; i < NumberOfElement; i++) {
		list >> cur;
		if (i == 0) {
			max = cur;
			min = cur;
		}
		if (max < cur)
			max = cur;
		if (min > cur)
			min = cur;
		L.push_back(cur);
	}
}
MaxInterval::~MaxInterval() {
	vector<double>().swap(L);//free the memory of vector
}
double MaxInterval::CaluculateMaxInterval(int N, vector<double> &L) {
	double BucketSize = (max - min) / (N - 1);
	vector<Bucket> B;
	for (int i = 0; i < N - 1; i++) {
		Bucket temp;
		if (i == 0)
			temp.minx = min;
		if (i == N - 2)
			temp.maxx = max;
		B.push_back(temp);
	}
	// put the element into the bucket
	for (int i = 0; i < N; i++) {
		int index = L[i] - min / BucketSize;
		if (index >= N - 1) {
			index = N - 2;
		}
		B[index].number++;
		if (B[index].maxx < L[i]) {
			B[index].maxx = L[i];
		}
		if (B[index].minx > L[i]) {
			B[index].minx = L[i];
		}
	}
	// find the Max Interval
	if (N == 2) {
		MaxGap = max - min;
	}
	else {
		MaxGap = -INFINITY;
	}
	for (int i = 1; i < N - 1; i++) {
		if (B[i].minx == INFINITY)
			B[i].minx = B[i - 1].maxx;
		if (MaxGap < (B[i].minx - B[i - 1].maxx))
			MaxGap = B[i].minx - B[i - 1].maxx;
		if (B[i].maxx == -INFINITY)
			B[i].maxx = B[i].minx;
	}
	ofstream output("output.txt", ios::out);
	output << MaxGap << endl;
	return MaxGap;
}
int main(int argc,int **argv) {
	MaxInterval solution("input.txt");
	double MaxGap = solution.CaluculateMaxInterval(solution.NumberOfElement, solution.L);
	cout << MaxGap << endl;
	return 0;
}