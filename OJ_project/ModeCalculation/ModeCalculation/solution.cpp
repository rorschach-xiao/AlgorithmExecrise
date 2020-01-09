#include <iostream>
#include <vector>
using namespace std;
class ModeSolution {
public:
	vector<int> multiset;
	int N;
	int Mode;
	int MaxCnt = 0;

	ModeSolution(int n);
	~ModeSolution();

	void Split(int start,int end, int &left, int &right);
	void GetMode(int start, int end);
	void QuickSort(vector<int> &v,int start,int end);
};
ModeSolution::ModeSolution(int n) {
	int temp;
	N = n;
	for (int i = 0; i < n; i++) {
		temp = rand() % 20 + 1;
		multiset.push_back(temp);
	}
	multiset.push_back(-1);
}
ModeSolution::~ModeSolution() {
	vector<int>().swap(multiset);
}
void ModeSolution::QuickSort(vector<int> &v, int start, int end) {
	if (v.size() == 0)
		return;
	if (start >= end)
		return;
	int cardinal = v[start];
	int i = start, j = end;
	while (i != j) {
		while (v[j] >= cardinal && i<j) {
			--j;
		}
		while (v[i] <= cardinal && i<j) {
			++i;
		}
		if (i<j) {
			int temp;
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
		
	}
		v[start] = v[i];
		v[i] = cardinal;
		QuickSort(v, start, i-1);
		QuickSort(v, i+1, end);

}
void ModeSolution::Split(int start,int end, int &left, int &right) {
	int mid = (start + end) / 2;
	for (left = 0; left < N; left++) {
		if (multiset[left] == multiset[mid]) {
			break;
		}
	}
	for (right = left + 1; right < N; right++) {
		if (multiset[right] != multiset[mid]) {
			break;
		}
	}
}
void ModeSolution::GetMode(int start,int end) {
	if (start >= end)
		return;
	int left, right;
	Split(start, end, left, right);
	int mid = (end + start) / 2;
	int cnt = right - left;
	if (cnt > MaxCnt) {
		MaxCnt = cnt;
		Mode = multiset[mid];
	}
	if (left - start + 1 > cnt) {
		GetMode(start, left - 1);
	}
	if (end - right + 1>cnt){
		GetMode(right, end);
	}
}
int main(int argc,char **argv) {
	ModeSolution s1(20);
	s1.QuickSort(s1.multiset,0,s1.N-1);
	s1.GetMode(0, s1.N-1);
	cout << "众数为：" << s1.Mode<<"重数为："<<s1.MaxCnt<<endl;
	system("pause");
	return 0;
}
